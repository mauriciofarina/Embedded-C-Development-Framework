/**
 * @file at45db161e.c
 * @author Mauricio Dall Oglio Farina
 * @brief LittleFS FileSystem Library AT45DB161E Device Implementation
 */
#ifdef USE_LITTLEFS
#ifdef USE_DEVICE_AT45DB161E
#include "filesystem/littlefs/lib_filesystem_littlefs_private.h"

#include "at45db161e/dev_at45db161e.h"

#include "gpio/mid_gpio.h"
#include "spi/mid_spi.h"
#include "system/mid_system.h"

#define ACCESS_TRIES     300 /** Number of tries before access fail */
#define ACCESS_TRY_DELAY 1   /** Time between access tries (ms) */

static at45db161e_t handler; /** Device Handler */

#ifdef USE_RTOS_KERNEL
static rtos_binary_semaphore_t transfer_completed = {0}; /** Transfer Completed Semaphore */
#else
static volatile bool transfer_completed = false; /** Transfer Completed Flag */
#endif

/**
 * @brief SPI Chip Select
 *
 * @param enable[in] enable/disable chip select
 */
static inline void chip_select(bool enable) {
    mid_gpio_set_pin(MID_GPIO_FLASH_CS, !enable);
}

/**
 * @brief Transfer Completed Callback
 */
static inline void spi_transfer_completed_callback(void) {
#ifdef USE_RTOS_KERNEL
    assert(cls_rtos_binary_semaphore_give_isr(&transfer_completed));
#else
    transfer_completed = true;
#endif
}

/**
 * @brief Send SPI Data
 *
 * @param data[in] TX Data
 * @param size[in] Data Size (Bytes)
 *
 * @return true Success
 * @return false Communication Failed
 */
static inline bool spi_send(void *data, uint32_t size) {
    bool result = mid_spi_external_flash_send(data, size);
    if (result) {
#ifdef USE_RTOS_KERNEL
        result = cls_rtos_binary_semaphore_take_default(&transfer_completed);
#else
        while (!transfer_completed) {
        }
        transfer_completed = false;
#endif
    }
    return result;
}

/**
 * @brief Receive SPI Data
 *
 * @param data[out] RX Data
 * @param size[in] Data Size (Bytes)
 *
 * @return true Success
 * @return false Communication Failed
 */
static inline bool spi_receive(void *data, uint32_t size) {
    bool result = mid_spi_external_flash_receive(data, size);
    if (result) {
#ifdef USE_RTOS_KERNEL
        result = cls_rtos_binary_semaphore_take_default(&transfer_completed);
#else
        while (!transfer_completed) {
        }
        transfer_completed = false;
#endif
    }
    return result;
}

void memory_device_init(void) {

#ifdef USE_RTOS_KERNEL
    cls_rtos_binary_semaphore_init(&transfer_completed);
#endif

    mid_spi_external_flash_register_completed_callback(spi_transfer_completed_callback);

    at45db161e_init_t init = {
        .tries = ACCESS_TRIES,
        .try_delay = ACCESS_TRY_DELAY,

        .spi_send = spi_send,
        .spi_receive = spi_receive,
        .spi_chip_select = chip_select,

#ifdef USE_RTOS_KERNEL
        .delay = lib_rtos_delay,
#else
        .delay = mid_system_delay,
#endif
    };

    dev_at45db161e_init(&handler, &init);

    assert(dev_at45db161e_is_device_ready(&handler));
    assert(dev_at45db161e_set_page_size(&handler));
    assert(dev_at45db161e_is_device_ready(&handler));
    assert(dev_at45db161e_has_valid_device_id(&handler));
}

uint32_t get_device_number_of_pages(void) {
    return handler.number_of_pages;
}
uint32_t get_device_block_size(void) {
    return handler.page_size;
}
uint32_t get_device_read_size(void) {
    return handler.page_size;
}
uint32_t get_device_write_size(void) {
    return handler.page_size;
}
uint32_t get_device_cache_size(void) {
    return handler.page_size;
}

int littlefs_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size) {

    (void)c;

    int error = LFS_ERR_IO;

    assert(0 == off);                  // Does not allow offset
    assert(size == handler.page_size); // Only allows Page Size Operations

    if (dev_at45db161e_is_device_ready(&handler)) {
        if (dev_at45db161e_read_page(&handler, buffer, block)) {
            error = LFS_ERR_OK;
        }
    }

    return error;
}

int littlefs_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size) {

    (void)c;

    int error = LFS_ERR_IO;

    assert(0 == off);                  // Does not allow offset
    assert(size == handler.page_size); // Only allows Page Size Operations

    if (dev_at45db161e_is_device_ready(&handler)) {
        if (dev_at45db161e_write_page(&handler, (void *)buffer, block)) {
            error = LFS_ERR_OK;
        }
    }
    return error;
}

int littlefs_erase(const struct lfs_config *c, lfs_block_t block) {

    (void)c;

    int error = LFS_ERR_IO;

    if (dev_at45db161e_is_device_ready(&handler)) {
        if (dev_at45db161e_erase_page(&handler, block)) {
            error = LFS_ERR_OK;
        }
    }

    return error;
}

int littlefs_sync(const struct lfs_config *c) {

    (void)c;

    // Not Necessary, Read and Write always hits memory
    return LFS_ERR_OK;
}

#endif
#endif
