/**
 * @file dev_mbi5025.c
 * @author Mauricio Dall Oglio Farina
 * @brief LED Driver MBI5025
 */
#include "dev_mbi5025.h"

void dev_mbi5025_init(mbi5025_t *const handler, mbi5025_init_t *const init) {

    assert(init->devices > 0);
    handler->devices = init->devices;
    assert(init->data != NULL);
    handler->data = init->data;

    // Disable all Output Pins
    // Output Pins set with value 1 are disabled and 0 are enabled
    memset(handler->data, 0xFF, (sizeof(uint16_t) * handler->devices));

    assert(init->spi_send != NULL);
    handler->spi_send = init->spi_send;
    assert(init->gpio_set_latch != NULL);
    handler->gpio_set_latch = init->gpio_set_latch;
    assert(init->gpio_set_enable != NULL);
    handler->gpio_set_enable = init->gpio_set_enable;

    handler->gpio_set_enable(false); // Enable Outputs
}

void dev_mbi5025_set_pin(mbi5025_t *const handler, uint32_t index, uint32_t pin, bool enable) {

    assert(index < handler->devices);
    assert(pin < DEV_MBI5025_MAX_PIN);

    if (enable) {
        handler->data[index] &= ~(1 << pin);
    } else {
        handler->data[index] |= (1 << pin);
    }
}

void dev_mbi5025_update(mbi5025_t *const handler) {
    handler->gpio_set_latch(false);
    handler->spi_send(handler->data, (sizeof(uint16_t) * handler->devices));
    handler->gpio_set_latch(true);
}

void dev_mbi5025_enable(mbi5025_t *const handler, bool enable) {
    handler->gpio_set_latch(!enable);
}