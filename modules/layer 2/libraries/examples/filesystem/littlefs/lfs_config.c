/**
 * @file lfs_config.c
 * @author Mauricio Dall Oglio Farina
 * @brief LittleFS FileSystem Customizations
 */
#ifdef USE_LITTLEFS
#include "lfs_config.h"

//*************************************************
//
// Customized Implementations
//
//*************************************************

#include "heap/cls_heap_1.h"

static heap_1_t heap = {0};
static uint64_t heap_buffer[LIB_FILESYSTEM_LITTLEFS_HEAP_SIZE] = {0};
static heap_1_allocation_t heap_allocations_buffer[LIB_FILESYSTEM_LITTLEFS_HEAP_MAX_ALLOCATIONS] = {0};

void lfs_config_init(void) {

    heap_1_init_t init = {
        .super = {
            .size = sizeof(heap_buffer),
            .buffer = (uint8_t *)heap_buffer,
        },

        .item_size = sizeof(uint64_t), // Library Requires 64 bit alignment
        .max_allocations = LIB_FILESYSTEM_LITTLEFS_HEAP_MAX_ALLOCATIONS,
        .allocation = heap_allocations_buffer,
    };

    cls_heap_1_init(&heap, &init);
}

void *lfs_malloc(size_t size) {
    void *pointer = cls_heap_malloc((heap_t *)&heap, size);
    assert(pointer); // Should always have enough memory space
    return pointer;
}

void lfs_free(void *p) {
    cls_heap_free((heap_t *)&heap, p);
}

//*************************************************
//
// Unchanged Implementations From lfs_util.c
//
//*************************************************

// Software CRC implementation with small lookup table
uint32_t lfs_crc(uint32_t crc, const void *buffer, size_t size) {
    static const uint32_t rtable[16] = {
        0x00000000,
        0x1db71064,
        0x3b6e20c8,
        0x26d930ac,
        0x76dc4190,
        0x6b6b51f4,
        0x4db26158,
        0x5005713c,
        0xedb88320,
        0xf00f9344,
        0xd6d6a3e8,
        0xcb61b38c,
        0x9b64c2b0,
        0x86d3d2d4,
        0xa00ae278,
        0xbdbdf21c,
    };

    const uint8_t *data = buffer;

    for (size_t i = 0; i < size; i++) {
        crc = (crc >> 4) ^ rtable[(crc ^ (data[i] >> 0)) & 0xf];
        crc = (crc >> 4) ^ rtable[(crc ^ (data[i] >> 4)) & 0xf];
    }

    return crc;
}

#endif