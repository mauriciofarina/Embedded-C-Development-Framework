/**
 * @file cls_heap_3.c
 * @author Mauricio Dall Oglio Farina (mauricio.farina@mobitec.com.br)
 * @brief Heap 3 Class
 * @version 1.0
 * @date 2022-09-04
 *
 * Luminator LATAM Firmware C Code Standard V2.0
 *
 * @copyright Copyright (C) 2022 Luminator Technology Group LLC or its affiliates. All Rights Reserved.
 *
 */
#include "cls_heap_3.h"

/**
 * @brief Allocate Memory
 *
 * @param handler[in] Handler
 * @param size[in] Allocation Size.
 *
 * @return void* Allocation Pointer
 * @return NULL Allocation Failed
 */
static void *heap_3_malloc(heap_t *const handler, uint32_t size);

/**
 * @brief Free Allocated Memory
 *
 * @details Will Always Free The Whole Heap Memory
 *
 * @param handler[in] Handler
 * @param pointer[in] Allocation Pointer (Should always be NULL)
 */
static void heap_3_free(heap_t *const handler, void *const pointer);

static void *heap_3_malloc(heap_t *const handler, uint32_t size) {

    void *pointer = NULL;

    if (size > 0) {

        heap_3_t *heap = (heap_3_t *)handler;

        if (handler->lock) {
            if (!handler->lock()) {
                goto end;
            }
        }

        if ((heap->index + size) > handler->size) {
            goto end;
        }

        uint8_t *buffer = handler->buffer;
        pointer = (void *)&buffer[heap->index];
        heap->index += size;

        if (handler->unlock) {
            handler->unlock();
        }
    }

end:
    return pointer;
}

static void heap_3_free(heap_t *const handler, void *const pointer) {

    assert(NULL == pointer); // Pointer Must be NULL Since we always free the whole memory

    heap_3_t *heap = (heap_3_t *)handler;

    if (handler->lock) {
        assert(handler->lock());
    }

    memset(handler->buffer, 0, handler->size);
    heap->index = 0;

    if (handler->unlock) {
        handler->unlock();
    }
}

void cls_heap_3_init(heap_3_t *const handler, heap_3_init_t *const init) {

    cls_heap_init((heap_t *)handler, (heap_init_t *)init);

    handler->index = 0;

    static const struct heap_api api = {
        .malloc = heap_3_malloc,
        .free = heap_3_free,
    };
    handler->super.api = &api;
}