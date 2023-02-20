/**
 * @file dev_name.c
 * @author Your Name
 * @brief Name Device
 */
// Module Includes
#include "dev_name.h"

// Private Functions Implementations
static uint32_t add_values(name_t *const handler) {
    return (handler->value_0 + handler->value_1);
}

// Initialization Functions Implementation
void dev_name_init(name_t *const handler, name_init_t *const init) {

    // Instance Initialization
    handler->value_0 = init->value_0;
    handler->value_1 = init->value_1;

    assert(init->send != NULL); // Required API functions must be asserted
    handler->send = init->send;
}

// Public Functions Implementation
void dev_name_enable(name_t *const handler, bool enable) {
    // Function Implementation
}