/**
 * @file app_name.h
 * @author Your Name
 * @brief Application Name
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __APP_NAME_H__
#define __APP_NAME_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Other Public Headers go here
#include "app_name_types.h"

// Defines and Macros go here
#define APP_NAME_DEFAULT_VALUE 0 /** Default Value */

// Enumerations and Structs should be declared in app_name_types.h

// Initialization prototype goes here

/**
 * @brief Initialize Application
 */
void app_name_init(void);

/**
 * @brief Start Application
 */
void app_name_start(void);

#endif