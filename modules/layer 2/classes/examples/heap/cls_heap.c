/**
 * @file cls_heap.c
 * @author Mauricio Dall Oglio Farina
 * @brief Heap Inteface Class
 */
#include "cls_heap.h"

static void *malloc_interface(heap_t *const handler, uint32_t size) {
    (void)handler;
    (void)size;
    assert(0); // No Implementation
    return NULL;
}

static void free_inteface(heap_t *const handler, void *const pointer) {
    (void)handler;
    (void)pointer;
    assert(0); // No Implementation
}

void cls_heap_init(heap_t *const handler, heap_init_t *const init) {

    assert(init->buffer);
    handler->buffer = init->buffer;

    assert(init->size);
    handler->size = init->size;

    static const struct heap_api api = {
        .malloc = malloc_interface,
        .free = free_inteface,
    };
    handler->api = &api;

    assert((init->lock && init->unlock) || (!init->lock && !init->unlock)); // Require both functions for Thread Safe Implementation
    handler->lock = init->lock;
    handler->unlock = init->unlock;
}