/**
 * @file mid_name.h
 * @author Your Name
 * @brief Name Middleware Interface
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __MID_NAME_H__
#define __MID_NAME_H__

// Required C standard libraries
#include <stdint.h>
// No other header files should be included here

// Defines and macros goes here
#define MID_NAME_DEFAULT_VALUE 0 /** Default Value */

// Enumerations goes here
/**
 * @brief Name Type
 */
typedef enum {

    MID_NAME_TYPE_0 = 0, /** Type 0 */
    MID_NAME_TYPE_1,     /** Type 1 */
    MID_NAME_TYPE_2,     /** Type 2 */

} mid_name_type_t; // Prefer singular naming (type instead of types)

// Struct goes here
/**
 * @brief Name Information
 */
typedef struct {
    mid_name_type_t type; /** Type */
    uint32_t value;       /** Value */
} mid_name_info_t;

// Function prototypes goes here
/**
 * @brief Get Name Info
 *
 * @details Describe here any important information
 * regarding how this function should be implemented.
 *
 * @param info[in] Name Information
 */
void mid_name_get_info(mid_name_info_t *info);

#endif