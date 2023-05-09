/**
 * @file lib_filesystem_littlefs_private.h
 * @author Mauricio Dall Oglio Farina
 * @brief LittleFS FileSystem Library Private Header
 */
#ifndef __LIB_FILESYSTEM_LITTLEFS_PRIVATE_H__
#define __LIB_FILESYSTEM_LITTLEFS_PRIVATE_H__

#ifdef USE_LITTLEFS

#include "lib_filesystem_littlefs.h"

#ifdef USE_RTOS_KERNEL
#include "rtos/lib_rtos.h"
#endif

/**
 * @brief Init Device
 *
 */
void memory_device_init(void);

/**
 * @brief Get the device number of pages
 *
 * @return uint32_t Number of Pages
 */
uint32_t get_device_number_of_pages(void);

/**
 * @brief Get the device block size
 *
 * @return uint32_t Block Size (Bytes)
 */
uint32_t get_device_block_size(void);

/**
 * @brief Get the device read size
 *
 * @return uint32_t Read Size (Bytes)
 */
uint32_t get_device_read_size(void);

/**
 * @brief Get the device write size
 *
 * @return uint32_t Write Size (Bytes)
 */
uint32_t get_device_write_size(void);

/**
 * @brief Get the device cache size
 *
 * @return uint32_t Cache Size (Bytes)
 */
uint32_t get_device_cache_size(void);

/**
 * @brief LittleFS Read Operation API
 *
 * @param c[in] Filesystem Configuration Handler
 * @param block[in] Memory Block
 * @param off[in] Block Offset (Bytes)
 * @param buffer[out] Read Data Buffer
 * @param size[in] Read Size (Bytes)
 *
 * @return LFS_ERR_OK Success
 * @return LFS_ERR_IO Communication Failed
 */
int littlefs_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size);

/**
 * @brief LittleFS Prog (Write) Operation API
 *
 * @param c[in] Filesystem Configuration Handler
 * @param block[in] Memory Block
 * @param off[in] Block Offset (Bytes)
 * @param buffer[in] Write Data Buffer
 * @param size[in] Write Size (Bytes)
 *
 * @return LFS_ERR_OK Success
 * @return LFS_ERR_IO Communication Failed
 */
int littlefs_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size);

/**
 * @brief LittleFS Erase Operation API
 *
 * @param c[in] Filesystem Configuration Handler
 * @param block[in] Memory Block
 *
 * @return LFS_ERR_OK Success
 * @return LFS_ERR_IO Communication Failed
 */
int littlefs_erase(const struct lfs_config *c, lfs_block_t block);

/**
 * @brief LittleFS Sync Operation API
 *
 * @param c[in] Filesystem Configuration Handler
 *
 * @return LFS_ERR_OK Success
 * @return LFS_ERR_IO Communication Failed
 */
int littlefs_sync(const struct lfs_config *c);

#endif
#endif