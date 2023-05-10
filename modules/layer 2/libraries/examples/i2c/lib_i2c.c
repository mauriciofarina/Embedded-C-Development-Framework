/**
 * @file lib_i2c.c
 * @author Mauricio Dall Oglio Farina
 * @brief I2C Library
 */
#include "lib_i2c.h"

#include "i2c/mid_i2c.h"

#include "rtos/lib_rtos.h"

static rtos_mutex_t i2c_mutex = {0}; /** I2C Mutex */

void lib_i2c_init(void) {

    cls_rtos_mutex_init(&i2c_mutex);
}

bool lib_i2c_scan(uint8_t address) {

    bool result = false;

    if (cls_rtos_mutex_lock_default(&i2c_mutex)) {

        result = mid_i2c_scan(address);
        cls_rtos_mutex_unlock(&i2c_mutex);
    }

    return result;
}

bool lib_i2c_send(uint8_t address, uint8_t *data, uint32_t size) {

    bool result = false;

    if (cls_rtos_mutex_lock_default(&i2c_mutex)) {

        result = mid_i2c_send(address, data, size);
        cls_rtos_mutex_unlock(&i2c_mutex);
    }

    return result;
}

bool lib_i2c_read(uint8_t address, uint8_t *data, uint32_t size) {

    bool result = false;

    if (cls_rtos_mutex_lock_default(&i2c_mutex)) {

        result = mid_i2c_read(address, data, size);
        cls_rtos_mutex_unlock(&i2c_mutex);
    }

    return result;
}
