/**
 * @file cls_heap_3.h
 * @author Mauricio Dall Oglio Farina
 * @brief Heap 3 Class
 */
#ifndef __CLS_HEAP_3_H__
#define __CLS_HEAP_3_H__

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
    heap_init_t super; /** Super Class Initialization */
} heap_3_init_t;

/**
 * @brief Class Handler
 *
 */
typedef struct {
    heap_t super;   /** Inherited Class */

    uint32_t index; /** Current Allocation Index */
} heap_3_t;

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_heap_3_init(heap_3_t *const handler, heap_3_init_t *const init);

#endif