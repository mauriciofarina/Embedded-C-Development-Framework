/**
 * @file cls_class.h
 * @author Your Name
 * @brief Class Template
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __CLS_CLASS_H__
#define __CLS_CLASS_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Other Public Headers go here
#include "cls_class_types.h"

// Module Dependencies go here

// If this is a Project Component, other project includes go here

// Defines and Macros go here

// Initialization and Object Structs go here
/**
 * @brief Initialization Parameters
 */
typedef struct {
} class_init_t;

/**
 * @brief Class Handler
 */
typedef struct {
    const struct class_api *api; /** Overridable API */
} class_t;

// Overridable Methods go here
/**
 * @brief Class Overridable API
 */
struct class_api {
    void (*some_method)(class_t *const handler); /** @ref cls_class_some_method */
};

// Other Enumerations and Structs should be declared in cls_class_types.h

// Constructor/Destructor prototypes go here
/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_class_init(class_t *const handler, class_init_t *const init);

// Overridable Methods calls go here

/**
 * @brief Some Method
 *
 * @param handler[in] Handler
 */
static inline void cls_class_some_method(class_t *const handler) {
    handler->api->some_method(handler);
}

// Other Public Function prototypes go here

#endif
