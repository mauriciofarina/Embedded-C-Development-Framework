/**
 * @file cls_heap.h
 * @author Mauricio Dall Oglio Farina
 * @brief Heap Interface Class
 */
#ifndef __CLS_HEAP_H__
#define __CLS_HEAP_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Class Initialization Parameters
 *
 */
typedef struct {

    uint32_t size; /** Memory Pool Size (Bytes) */
    void *buffer;  /** Memory Pool Buffer. Must be @ref size Size */

    // (Optional) Multi-Thread Support Functions

    /**
     * @brief Lock Mutex Function
     *
     * @return true Mutex Locked
     * @return false Failed to Lock Mutex
     */
    bool (*lock)(void);

    /**
     * @brief Unlock Mutex Function
     */
    void (*unlock)(void);

} heap_init_t;

/**
 * @brief Class Handler
 *
 */
typedef struct {

    void *buffer;  /** Memory Pool Buffer. Must be @ref size Size */
    uint32_t size; /** Memory Pool Size (Bytes) */

    // Multi-Thread Support Functions (Optional)
    bool (*lock)(void);         /** Lock Mutex Function */
    void (*unlock)(void);       /** Unlock Mutex Function */

    const struct heap_api *api; /** Overridable API */

} heap_t;

/**
 * @brief Class Overridable API
 *
 */
struct heap_api {
    void *(*malloc)(heap_t *const handler, uint32_t size);    /** @ref cls_heap_malloc */
    void (*free)(heap_t *const handler, void *const pointer); /** @ref cls_heap_free */
};

/**
 * @brief Create Class Object
 *
 * @param handler[out] Handler
 * @param init[in] Initialization Parameters
 */
void cls_heap_init(heap_t *const handler, heap_init_t *const init);

/**
 * @brief Allocate Heap Memory
 *
 * @param handler[in] Handler
 * @param size[in] Allocation Size.
 *
 * @return void* Allocation Pointer
 * @return NULL Allocation Failed
 */
static inline void *cls_heap_malloc(heap_t *const handler, uint32_t size) {
    return handler->api->malloc(handler, size);
}

/**
 * @brief Free Allocated Memory
 *
 * @param handler[in] Handler
 * @param pointer[in] Allocation Pointer
 */
static inline void cls_heap_free(heap_t *const handler, void *const pointer) {
    handler->api->free(handler, pointer);
}

#endif