/**
 * @file cls_heap_1.c
 * @author Mauricio Dall Oglio Farina
 * @brief Heap 1 Class
 */
#include "cls_heap_1.h"

/**
 * @brief Get Next Available Allocation Item
 *
 * @param handler[in] Handler
 *
 * @return heap_1_allocation_t* Allocation Item Pointer
 * @return NULL Failed, No Allocation Item Available
 */
static heap_1_allocation_t *get_item(heap_1_t *const handler);

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
static void *heap_1_malloc(heap_t *const handler, uint32_t size);

/**
 * @brief Free Allocated Memory
 *
 * @param handler[in] Handler
 * @param pointer[in] Allocation Pointer
 */
static void heap_1_free(heap_t *const handler, void *const pointer);

// *******************************
//
// Private Implementations
//
// *******************************

static heap_1_allocation_t *get_item(heap_1_t *const handler) {

    heap_1_allocation_t *item = NULL;

    for (uint32_t i = 0; i < handler->max_allocations; ++i) {

        if ((NULL == handler->allocation[i].address) && (0 == handler->allocation[i].size)) {
            item = &handler->allocation[i];
            break;
        }
    }
    return item;
}

static void *heap_1_malloc(heap_t *const handler, uint32_t size) {

    void *pointer = NULL;

    heap_1_t *heap = (heap_1_t *)handler;

    if (handler->lock) {
        if (!handler->lock()) {
            goto end;
        }
    }

    // Round Up Size
    size = 1 + ((size - 1) / heap->item_size);
    size *= heap->item_size;

    uint8_t *address = handler->buffer;
    heap_1_allocation_t *item = heap->allocation;
    while (item != NULL) {

        // Check if can allocate memory
        if ((NULL == item->address) && (item->size >= size)) {

            item->address = address; // Claim Address

            if (item->size != size) {

                if (NULL == item->next) {

                    // Add new Item to Hold Free Space
                    item->next = get_item(heap);

                    if (item->next != NULL) {
                        item->next->size = (item->size - size);
                        item->size = size;
                    } // Else, There is no available items left, allocation will use all free region space

                } else if (item->next->address) {

                    // Add new Item to Hold Free Space Between the two allocations
                    heap_1_allocation_t *next = get_item(heap);

                    if (next != NULL) {
                        next->size = (item->size - size);
                        next->next = item->next;
                        item->size = size;
                        item->next = next;
                    } // Else, There is no available items left, allocation will use all free region space

                } else {
                    item->next->size += (item->size - size); // Add Free Space Left to Next Item
                    item->size = size;
                }
            }

            pointer = item->address;
            break;

        } else {
            address += item->size;
        }

        item = item->next;
    }

    if (handler->unlock) {
        handler->unlock();
    }

end:
    return pointer;
}

static void heap_1_free(heap_t *const handler, void *const pointer) {

    heap_1_t *heap = (heap_1_t *)handler;

    if (handler->lock) {
        assert(handler->lock());
    }

    heap_1_allocation_t *back = NULL;
    heap_1_allocation_t *item = heap->allocation;
    heap_1_allocation_t *next = NULL;

    while (item != NULL) {

        if (item->next != NULL) {
            next = item->next;
        } else {
            next = NULL;
        }

        if (pointer == item->address) {

            item->address = NULL; // Free Address

            if ((back != NULL) && (NULL == back->address)) {

                // Combine back and item
                // Always Keep First Item to Ensure that heap->allocation Index 0 is always a valid item
                back->size += item->size;
                back->next = item->next;

                // Free Allocation Item
                item->size = 0;
                item->next = NULL;

                item = back;
            }

            if ((next != NULL) && (NULL == next->address)) {

                // Combine item and next
                // Always Keep First Item to Ensure that heap->allocation Index 0 is always a valid item
                item->size += next->size;
                item->next = next->next;

                // Free next Allocation Item
                next->size = 0;
                next->next = NULL;
            }

            break;

        } else {

            back = item;
            item = item->next;
        }
    }

    if (handler->unlock) {
        handler->unlock();
    }
}

// *******************************
//
// Public Implementations
//
// *******************************

void cls_heap_1_init(heap_1_t *const handler, heap_1_init_t *const init) {

    cls_heap_init((heap_t *)handler, (heap_init_t *)init);

    if (init->item_size != 0) {
        handler->item_size = init->item_size;
    } else {
        handler->item_size = 1; // Default 1 Byte size
    }

    assert(init->max_allocations);
    handler->max_allocations = init->max_allocations;

    assert(init->allocation);
    handler->allocation = init->allocation;

    static const struct heap_api api = {
        .malloc = heap_1_malloc,
        .free = heap_1_free,
    };
    handler->super.api = &api;

    // Initialize Allocation Items
    memset(handler->allocation, 0x00, handler->max_allocations * sizeof(heap_1_allocation_t));
    handler->allocation[0].size = handler->super.size;
}