/**
 * @file cls_class.c
 * @author Your Name
 * @brief Class Template
 */
#include "cls_class.h"
#include "cls_class_private.h"

static void some_method(class_t *const handler) {
    // Method Implementation
}

void cls_class_init(class_t *const handler, class_init_t *const init) {

    // TODO: Initialization

    static const struct class_api api = {
        .some_method = some_method,
    };
    handler->api = &api;
}
