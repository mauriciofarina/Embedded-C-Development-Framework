/**
 * @file app_name_types.h
 * @author Your Name
 * @brief Application Name
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __APP_NAME_TYPES_H__
#define __APP_NAME_TYPES_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Type Definition defines go here
#define APP_NAME_DEFAULT_VALUE 0 /** Default Value */

// Enumerations go here
/**
 * @brief Name Mode
 */
typedef enum {

    APP_NAME_MODE_0 = 0, /** Mode 0 */
    APP_NAME_MODE_1,     /** Mode 1 */
    APP_NAME_MODE_2,     /** Mode 2 */

} app_name_mode_t; // Prefer singular naming (mode instead of modes)

// Structs go here
/**
 * @brief Name Information
 */
typedef struct {
    uint32_t info_0; /** Information 0 */
    uint32_t info_1; /** Information 1 */
} app_name_info_t;

// No function prototypes should be declared in this file

#endif