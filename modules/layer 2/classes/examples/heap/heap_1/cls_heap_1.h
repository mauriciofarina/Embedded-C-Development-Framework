/**
 * @file cls_heap_1.h
 * @author Mauricio Dall Oglio Farina (mauricio.farina@mobitec.com.br)
 * @brief Heap 1 Class
 * @version 1.0
 * @date 2022-06-23
 *
 * Luminator LATAM Firmware C Code Standard V2.0
 *
 * @copyright Copyright (C) 2022 Luminator Technology Group LLC or its affiliates. All Rights Reserved.
 *
 */
#ifndef __CLS_HEAP_1_H__
#define __CLS_HEAP_1_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "cls_heap.h"

/**
 * @brief Allocation Item
 *
 */
typedef struct heap_1_allocation {
    void *address;                  /** Allocation Start Address (NULL is Free Space) */
    uint32_t size;                  /** Allocation Size or Free Space (Bytes) */
    struct heap_1_allocation *next; /** Next Allocation Item */
} heap_1_allocation_t;

/**
 * @brief Class Initialization Parameters
 *
 */
typedef struct {

    heap_init_t super; /** Super Class Initialization */

    uint32_t item_size;              /** Allocation Item Size (Bytes). Allocations are multiples of this value */
    uint32_t max_allocations;        /** Max Number of Pool Allocations */
    heap_1_allocation_t *allocation; /** Allocations Buffer. Must be ( @ref max_allocations * sizeof( @ref heap_1_allocation_t)) Bytes */

} heap_1_init_t;

/**
 * @brief Class Handler
 *
 */
typedef struct {

    heap_t super; /** Inherited Class */

    uint32_t item_size;              /** Allocation Item Size (Bytes). Allocations are multiples of this value */
    uint32_t max_allocations;        /** Max Number of Pool Allocations */
    heap_1_allocation_t *allocation; /** Allocations Buffer. Must be ( @ref max_allocations * sizeof( @ref heap_1_allocation_t)) Bytes */

} heap_1_t;

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_heap_1_init(heap_1_t *const handler, heap_1_init_t *const init);

#endif