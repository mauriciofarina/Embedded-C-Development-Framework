/**
 * @file cls_interface_class.h
 * @author Your Name
 * @brief Interface Class Template
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __CLS_INTERFACE_CLASS_H__
#define __CLS_INTERFACE_CLASS_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Other Public Headers go here
#include "cls_interface_class_types.h"

// Module Dependencies go here

// If this is a Project Component, other project includes go here

// Defines and Macros go here

// Initialization and Object Structs go here
/**
 * @brief Initialization Parameters
 */
typedef struct {
} interface_class_init_t;

/**
 * @brief Class Handler
 */
typedef struct {
    const struct interface_class_api *api; /** Overridable API */
} interface_class_t;

// Overridable Methods go here
/**
 * @brief Class Overridable API
 */
struct interface_class_api {
    void (*some_method)(interface_class_t *const handler); /** @ref cls_interface_class_some_method */
};

// Other Enumerations and Structs should be declared in cls_class_types.h

// Constructor/Destructor prototypes go here
/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_interface_class_init(interface_class_t *const handler, interface_class_init_t *const init);

// Overridable Methods calls go here

/**
 * @brief Some Method
 *
 * @param handler[in] Handler
 */
static inline void cls_interface_class_some_method(interface_class_t *const handler) {
    handler->api->some_method(handler);
}

// Other Public Function prototypes go here

#endif
