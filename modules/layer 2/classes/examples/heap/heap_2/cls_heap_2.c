/**
 * @file cls_heap_2.c
 * @author Mauricio Dall Oglio Farina (mauricio.farina@mobitec.com.br)
 * @brief Heap 2 Class
 * @version 1.0
 * @date 2022-06-23
 *
 * Luminator LATAM Firmware C Code Standard V2.0
 *
 * @copyright Copyright (C) 2022 Luminator Technology Group LLC or its affiliates. All Rights Reserved.
 *
 */
#include "cls_heap_2.h"

/**
 * @brief Allocate Memory
 *
 * @note If @ref size is not a multiple of @ref handler->item_size
 * @ref size will be rounded up
 *
 * @param handler[in] Handler
 * @param size[in] Allocation Size.
 *
 * @return void* Allocation Pointer
 * @return NULL Allocation Failed
 */
static void *heap_2_malloc(heap_t *const handler, uint32_t size);

/**
 * @brief Free Allocated Memory
 *
 * @param handler[in] Handler
 * @param pointer[in] Allocation Pointer
 */
static void heap_2_free(heap_t *const handler, void *const pointer);

//*******************************
//
// Private Implementations
//
//*******************************

static void *heap_2_malloc(heap_t *const handler, uint32_t size) {

    void *pointer = NULL;

    heap_2_t *heap = (heap_2_t *)handler;

    if (size != heap->item_size) {
        goto end;
    }

    if (handler->lock) {
        if (!handler->lock()) {
            goto end;
        }
    }

    uint32_t end_index = (heap->max_allocations * heap->item_size);

    uint32_t allocation_index = 0;
    uint8_t allocation_bit = (1 << 7);

    for (uint32_t i = 0; i < end_index; i += heap->item_size) {

        if (!allocation_bit) {
            allocation_index++;
            allocation_bit = (1 << 7);
        }

        // Check for Free Space
        if (!(heap->allocation[allocation_index] & allocation_bit)) {
            heap->allocation[allocation_index] |= allocation_bit;
            pointer = &((uint8_t *)handler->buffer)[i];
            break;
        }

        allocation_bit >>= 1;
    }

    if (handler->unlock) {
        handler->unlock();
    }

end:
    return pointer;
}

static void heap_2_free(heap_t *const handler, void *const pointer) {

    heap_2_t *heap = (heap_2_t *)handler;

    if (handler->lock) {
        assert(handler->lock());
    }

    uint32_t buffer_index = ((uint32_t)pointer - (uint32_t)handler->buffer);
    uint32_t item = (buffer_index / heap->item_size);

    assert(pointer == (void *)&((uint8_t *)handler->buffer)[buffer_index]); // Verify if trying to free invalid allocation

    uint32_t allocation_byte = (item / 8);
    uint8_t allocation_bit = (1 << (7 - (item % 8)));

    heap->allocation[allocation_byte] &= ~allocation_bit;

    if (handler->unlock) {
        handler->unlock();
    }
}

//*******************************
//
// Public Implementations
//
//*******************************

void cls_heap_2_init(heap_2_t *const handler, heap_2_init_t *const init) {

    cls_heap_init((heap_t *)handler, (heap_init_t *)init);

    if (init->item_size != 0) {
        handler->item_size = init->item_size;
    } else {
        handler->item_size = 1; // Default 1 Byte size
    }

    assert(init->max_allocations);
    handler->max_allocations = init->max_allocations;

    assert(handler->super.size == (handler->item_size * handler->max_allocations));

    assert(init->allocation);
    handler->allocation = init->allocation;

    static const struct heap_api api = {
        .malloc = heap_2_malloc,
        .free = heap_2_free,
    };
    handler->super.api = &api;

    // Initialize Allocation Items
    memset(handler->allocation, 0x00, handler->max_allocations * sizeof(uint8_t));
}
