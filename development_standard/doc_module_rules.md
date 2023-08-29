# Module Rules

1. Module files should respect the following access level:

    |    Postfix    |                Use                 |   Access   |
    | :-----------: | :--------------------------------: | :--------: |
    |     `.c`      |            Main Source             |  Private   |
    |     `.h`      |           Public Header            |   Public   |
    | `_private.h`  |           Private Header           |  Private   |
    |  `_types.h`   |         Type Declarations          |   Public   |
    | `_internal.h` |         Restricted Header          | Restricted |
    | `_override.c` | Class Override Methods Source Code | Restricted |
    | `_override.h` |   Class Override Methods Header    | Restricted |


1. Each header file should contain a preprocessor guard against multiple inclusion:

    ```c
    #ifndef __FILENAME_H__
    #define __FILENAME_H__
    ...
    #endif
    ```

1. The header file should identify only the procedures, constants, and data types (via prototypes or macros, `#define`, and `typedef`) about which it is strictly necessary for other modules to be informed.
    - Do not declare variables on header files (Headers containing `const` variable data only are exceptions)
    - Do not `extern` variables 
    - No storage for any variable should be allocated in a header file
    - Do not include any executable lines of code in a header file (Macros and `inline` Functions are exceptions)

1. No public header file should contain a `#include` of any private/restricted header file.

1. Each source file should `#include` only the behaviors appropriate to control one entity. Examples of entities include encapsulated data types, active objects, peripheral drivers (e.g., for a UART), and communication protocols or layers (e.g., ARP).

1. Each source file should always `#include` the header file of the same name (e.g., file `adc.c` should `#include "adc.h"`).

1. Absolute paths should not be used in `#include` file names.

1. Each source file should be free of unused `#include` files.

1. No source file should `#include` another source file.