# Heap Class

Heap (a.k.a. memory pool) implementations


# Available Classes

## Heap Class (Interface Class)

The heap interface class is intended as a base for all heap implementation versions.

## Heap 1 Class

Heap 1 implements an allocation system similar to standard `malloc` and `free` implementation, where memory can be individually allocated and released. The class, however, allows a maximum number of allocations at the same time. Also, a type size can be specified to allow data alignment.

## Heap 2 Class

Heap 2 provides a single type allocation implementation, where, only same-sized elements of the same type can be allocated. A good use case example is when you need to allocate objects of the same class dynamically. This way, the memory can be used completely, without any fragmentation problems.

## Heap 3 Class

Heap 3 implements a "add only" allocation system. Basically, you can allocate memory any size you want, but you can never deallocate any single allocation. The only way to deallocate memory is to fully reset/clean the heap memory. This implementation is great when you need to allocate items that will never be deallocated during the whole runtime lifetime, or are all related and can be deallocated as a group.