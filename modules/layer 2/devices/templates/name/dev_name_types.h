/**
 * @file dev_name_types.h
 * @author Mauricio Dall Oglio Farina
 * @brief Name Device
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __DEV_NAME_TYPES_H__
#define __DEV_NAME_TYPES_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Type Definition defines go here
#define DEV_NAME_DEFAULT_VALUE 0 /** Default Value */

// Enumerations go here
/**
 * @brief Name Mode
 */
typedef enum {

    DEV_NAME_MODE_0 = 0, /** Mode 0 */
    DEV_NAME_MODE_1,     /** Mode 1 */
    DEV_NAME_MODE_2,     /** Mode 2 */

} dev_name_mode_t; // Prefer singular naming (mode instead of modes)

// Structs go here
/**
 * @brief Name Information
 */
typedef struct {
    uint32_t info_0; /** Information 0 */
    uint32_t info_1; /** Information 1 */
} dev_name_info_t;

// No function prototypes should be declared in this file

#endif