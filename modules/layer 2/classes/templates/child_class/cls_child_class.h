/**
 * @file cls_child_class.h
 * @author Your Name
 * @brief Child Class Template
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __CLS_CHILD_CLASS_H__
#define __CLS_CHILD_CLASS_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Other Public Headers go here
#include "cls_child_class_types.h"

// Parent Class Includes go here
#include "parent_class/cls_parent_class.h"

// Module Dependencies go here

// If this is a Project Component, other project includes go here

// Defines and Macros go here

// Initialization and Object Structs go here
/**
 * @brief Initialization Parameters
 */
typedef struct {
    // Parent Class Initialization Parameters should always be the first member
    parent_class_init_t super; /** Super Class Initialization */
} child_class_init_t;

// Class Object Private Variables go here
// Do Never access these variables directly outside this module
/**
 * @brief Class Object Handler
 */
typedef struct {
    // Parent Class Handler should always be the first member
    parent_class_t super; /** Super Class */
} child_class_t;

// Other Enumerations and Structs should be declared in cls_child_class_types.h

// Constructor/Destructor prototypes go here

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_child_class_init(child_class_t *const handler, child_class_init_t *const init);

// Other Public Function prototypes go here

#endif
