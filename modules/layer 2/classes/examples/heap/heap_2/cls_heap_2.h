/**
 * @file cls_heap_2.h
 * @author Mauricio Dall Oglio Farina
 * @brief Heap 2 Class
 */
#ifndef __CLS_HEAP_2_H__
#define __CLS_HEAP_2_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "cls_heap.h"

/**
 * @brief Class Initialization Parameters
 *
 */
typedef struct {

    heap_init_t super;        /** Super Class Initialization */

    uint32_t item_size;       /** Allocation Item Size (Bytes). Allocations are multiples of this value */
    uint32_t max_allocations; /** Max Number of Pool Allocations */
    uint8_t *allocation;      /** Allocations Buffer. Must be the rounded up value of ( @ref max_allocations / 8) Bytes */

} heap_2_init_t;

/**
 * @brief Class Handler
 *
 */
typedef struct {

    heap_t super;             /** Inherited Class */

    uint32_t item_size;       /** Allocation Item Size (Bytes). Allocations are multiples of this value */
    uint32_t max_allocations; /** Max Number of Pool Allocations */
    uint8_t *allocation;      /** Allocations Buffer. Must be the rounded up value of ( @ref max_allocations / 8) Bytes */

} heap_2_t;

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_heap_2_init(heap_2_t *const handler, heap_2_init_t *const init);

#endif