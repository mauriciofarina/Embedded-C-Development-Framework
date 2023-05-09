/**
 * @file flash_emulator.c
 * @author Mauricio Dall Oglio Farina
 * @brief LittleFS FileSystem Library Flash Memory Device Emulator Implementation
 */
#ifdef USE_LITTLEFS
#ifdef USE_LITTLEFS_FLASH_EMULATOR
#include "filesystem/littlefs/lib_filesystem_littlefs_private.h"

#define EMULATOR_PAGES     128 /** Number of Memory Pages */
#define EMULATOR_PAGE_SIZE 128 /** Page Size (Bytes) */

static uint8_t data[EMULATOR_PAGES][EMULATOR_PAGE_SIZE] = {0};

void memory_device_init(void) {
    memset(data, 0xFF, sizeof(data));
}

uint32_t get_device_number_of_pages(void) {
    return EMULATOR_PAGES;
}
uint32_t get_device_block_size(void) {
    return EMULATOR_PAGE_SIZE;
}
uint32_t get_device_read_size(void) {
    return EMULATOR_PAGE_SIZE;
}
uint32_t get_device_write_size(void) {
    return EMULATOR_PAGE_SIZE;
}
uint32_t get_device_cache_size(void) {
    return EMULATOR_PAGE_SIZE;
}

int littlefs_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size) {

    (void)c;

    assert(0 == off);                   // Does not allow offset
    assert(size == EMULATOR_PAGE_SIZE); // Only allows Page Size Operations
    assert(block < EMULATOR_PAGES);     // Check if Valid Block

    memcpy(buffer, data[block], EMULATOR_PAGE_SIZE);

    return LFS_ERR_OK;
}

int littlefs_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size) {

    (void)c;

    assert(0 == off);                   // Does not allow offset
    assert(size == EMULATOR_PAGE_SIZE); // Only allows Page Size Operations
    assert(block < EMULATOR_PAGES);     // Check if Valid Block

    memcpy(data[block], buffer, EMULATOR_PAGE_SIZE);

    return LFS_ERR_OK;
}

int littlefs_erase(const struct lfs_config *c, lfs_block_t block) {

    (void)c;

    assert(block < EMULATOR_PAGES); // Check if Valid Block

    memset(data[block], 0xFF, EMULATOR_PAGE_SIZE);

    return LFS_ERR_OK;
}

int littlefs_sync(const struct lfs_config *c) {

    (void)c;

    // Not Necessary, Read and Write always hits memory
    return LFS_ERR_OK;
}

#endif
#endif
