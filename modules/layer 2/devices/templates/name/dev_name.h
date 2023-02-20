/**
 * @file dev_name.h
 * @author Mauricio Dall Oglio Farina
 * @brief Name Device
 */
// Never forget header guards
// Respect the following header guard naming convention
#ifndef __DEV_NAME_H__
#define __DEV_NAME_H__

// Required C standard libraries
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Other Public Internal Headers go here
#include "dev_name_types.h"

// Defines and Macros go here
#define DEV_NAME_DEFAULT_VALUE 0 /** Default Value */

// Initialization and Instance Structs go here

/**
 * @brief Initialization Parameters
 */
typedef struct {

    // Variables go here
    uint32_t value_0; /** Value 0 */
    uint32_t value_1; /** Value 1 */

    // External API functions go here
    /**
     * @brief Send Data
     *
     * @details Describe here any important information
     * regarding how this function should be implemented.
     *
     * @param data[in] Data
     * @param size[in] Size (Bytes)
     */
    void (*send)(void *data, uint32_t size);

} name_init_t;

// Device Instance Private Variables go here
// Do Never access these variables directly
/**
 * @brief Device Handler
 */
typedef struct {

    uint32_t value_0; /** Value 0 */
    uint32_t value_1; /** Value 1 */

    void (*send)(void *data, uint32_t size); /** Send Data */

} name_t;

// Other Enumerations and Structs should be declared on dev_name_types.h

// Initialization prototype goes here
/**
 * @brief Init Device
 *
 * @param handler[out] Device Handler
 * @param init[in] Initialization Parameters
 */
void dev_name_init(name_t *const handler, name_init_t *const init);

// Other Public Function prototypes go here
/**
 * @brief Enable/Disable Name Device
 *
 * @param handler[in] Handler
 * @param enable[in] Enable/Disable
 */
void dev_name_enable(name_t *const handler, bool enable);

#endif