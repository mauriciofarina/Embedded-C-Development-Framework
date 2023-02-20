/**
 * @file cls_interface_class.c
 * @author Your Name
 * @brief Interface Class Template
 */
#include "cls_interface_class.h"
#include "cls_interface_class_private.h"

/**
 * @ref cls_interface_class_some_method
 */
static inline void some_method(interface_class_t *const handler) {
    (void)handler;
    assert(0); // Interface Methods should always be overridden
}

void cls_interface_class_init(interface_class_t *const handler, interface_class_init_t *const init) {

    // TODO: Initialization

    static const struct interface_class_api api = {
        .some_method = some_method,
    };
    handler->api = &api;
}
