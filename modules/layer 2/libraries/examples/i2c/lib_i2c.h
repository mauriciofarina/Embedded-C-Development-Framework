/**
 * @file lib_i2c.h
 * @author Mauricio Dall Oglio Farina
 * @brief I2C Library
 */
#ifndef __LIB_I2C_H__
#define __LIB_I2C_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Initialize I2C Library
 *
 */
void lib_i2c_init(void);

/**
 * @brief Scan for device
 *
 * @param address[in] Device address
 *
 * @return true Device found
 * @return false No response
 */
bool lib_i2c_scan(uint8_t address);

/**
 * @brief Send data
 *
 * @param address[in] Device address
 * @param data[in] Data buffer
 * @param size[in] Data size (Bytes)
 *
 * @return true Success
 * @return false Fail
 */
bool lib_i2c_send(uint8_t address, uint8_t *data, uint32_t size);

/**
 * @brief
 *
 * @param address[in] Device address
 * @param data[in] Data buffer
 * @param size[in] Data size (Bytes)
 *
 * @return true Success
 * @return false Fail
 */
bool lib_i2c_read(uint8_t address, uint8_t *data, uint32_t size);

#endif
