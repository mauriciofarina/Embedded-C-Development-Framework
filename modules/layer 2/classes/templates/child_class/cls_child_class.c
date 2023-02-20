/**
 * @file cls_child_class.c
 * @author Your Name
 * @brief Child Class Template
 */
// Module Includes
#include "cls_child_class.h"
#include "cls_child_class_override.h"
#include "cls_child_class_private.h"

// Private Functions and Methods Implementations

// Constructor Method Implementation
void cls_child_class_init(child_class_t *const handler, child_class_init_t *const init) {

    // TODO: Initialization

    cls_parent_class_init(&handler->super, &init->super);

    static const struct parent_class_api api = {
        .some_method = cls_child_class_some_method,
    };
    handler->super.api = &api;
}

// Public Functions and Methods Implementation