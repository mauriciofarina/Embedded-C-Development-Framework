/**
 * @file dev_mbi5025.h
 * @author Mauricio Dall Oglio Farina
 * @brief LED Driver MBI5025
 */
#ifndef __DEV_MBI5025_H__
#define __DEV_MBI5025_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define DEV_MBI5025_MAX_PIN 16 /** Total Number of MBI Output Pins per Device */

/**
 * @brief Initialization Parameters
 */
typedef struct {

    uint32_t devices; /** Number of Cascaded MBI Devices */
    uint16_t *data;   /** MBI Data Buffer (Should have (sizeof(uint16_t) * @ref devices ) Bytes ) */

    /**
     * @brief Send SPI Data
     *
     * @details:
     * - Blocking Behavior Expected
     * - SPI Data Frame Size: 16 Bits
     * - SPI Clock Polarity: 0
     * - SPI Clock Phase: 0
     * - SPI Clock Max Frequency: 25 MHz
     *
     * @param data[in] Data
     * @param size[in] Size (Bytes)
     */
    void (*spi_send)(void *data, uint32_t size);

    /**
     * @brief Set Latch GPIO Pin
     *
     * @param enable[in] Enable/Disable Latch Pin
     */
    void (*gpio_set_latch)(bool enable);

    /**
     * @brief Set Output Enable GPIO Pin
     *
     * @param enable[in] Enable/Disable Output Enable Pin
     */
    void (*gpio_set_enable)(bool enable);

} mbi5025_init_t;

/**
 * @brief Device Handler
 */
typedef struct {

    uint32_t devices; /** Number of Cascaded MBI Devices */
    uint16_t *data;   /** MBI Data Buffer (Should have (sizeof(uint16_t) * @ref devices ) Bytes ) */

    void (*spi_send)(void *data, uint32_t size); /** Send SPI Data */
    void (*gpio_set_latch)(bool enable);         /** Set Latch GPIO Pin */
    void (*gpio_set_enable)(bool enable);        /** Set Output Enable GPIO Pin */

} mbi5025_t;

/**
 * @brief Init Device
 *
 * @param handler[out] Device Handler
 * @param init[in] Initialization Parameters
 */
void dev_mbi5025_init(mbi5025_t *const handler, mbi5025_init_t *const init);

/**
 * @brief Set MBI Output Pin
 *
 * @param handler[in] Handler
 * @param index[in] Cascade MBI Index
 * @param pin[in] MBI Pin
 * @param enable[in] Enable/Disable Output Pin
 */
void dev_mbi5025_set_pin(mbi5025_t *const handler, uint32_t index, uint32_t pin, bool enable);

/**
 * @brief Update MBI Outputs
 *
 * @param handler[in] Handler
 */
void dev_mbi5025_update(mbi5025_t *const handler);

/**
 * @brief Enable/Disable All MBI Outputs
 *
 * @param handler[in] Handler
 * @param enable[in] Enable/Disable Outputs
 */
void dev_mbi5025_enable(mbi5025_t *const handler, bool enable);

#endif