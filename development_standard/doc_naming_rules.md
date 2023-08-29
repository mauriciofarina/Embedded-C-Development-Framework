# Naming Rules

## Files

1. All file names should consist entirely of lowercase letters, numbers, and underscores. No spaces should appear within the header and source file names.

1. No header file name should share the name of a header file from the C Standard Library or C++ Standard Library. For example, modules should not be named `stdio.h` or `math.h`. 

1. Any module containing a `main()` function should have the word `main` as part of its source file name.

1. Whenever possible, name module files as follows:

    |     Filename      |                Use                 |
    | :---------------: | :--------------------------------: |
    |     `name.c`      |            Main Source             |
    |     `name.h`      |           Public Header            |
    | `name_private.h`  |           Private Header           |
    |  `name_types.h`   |         Type Declarations          |
    | `name_internal.h` |         Restricted Header          |
    | `name_override.c` | Class Override Methods Source Code |
    | `name_override.h` |   Class Override Methods Header    |

## Data Types

1. The names of all new data types, including structures, unions, and enumerations, should consist only of lowercase characters and internal underscores and end with `_t`.

1. All new structures, unions, and enumerations should be named via a `typedef`.

1. The name of all public data types should be prefixed with their module name and an underscore.

1. Enumerates items should always be uppercase characters and internal underscores and end with `,`.

    ```c
    typedef enum {
        ITEM_0,
        ITEM_1,
        ITEM_2, // Do not forget the "," on this one!
        
    } foo_t;
    ```


## Variables

1. No variable should have a name that is a keyword of C, C++, or any other well-known extension of the C programming language, including specifically K&R C and C99. Restricted names include `interrupt`, `inline`, `restrict`, `class`, `true`, `false`, `public`, `private`, `friend`, and `protected`.

1. No variable should have a name that overlaps with a variable name from the C Standard Library (e.g., `errno`).

1. No variable should have a name that begins with an underscore.

1. No variable name should be shorter than 3 characters (Unless extremely meaningful).

    ```c
    // Bad
    uint32_t e = 0; // Where e stands for event
    uint32_t ch = 0; // Where ch stands for channel

    // Acceptable
    // Where x and y stand for cartesian coordinates
    uint32_t x = 0; 
    uint32_t y = 0;

    // Acceptable
    for(uint32_t i = 0 ; i < 10 ; ++i) {}
    ```

1. No variable name should contain any uppercase letters.

1. No variable name should contain any numeric value that is called out elsewhere, such as the number of elements in an array.

    ```c
    // Bad
    uint8_t buffer_10[10];
    ```

1. Underscores should be used to separate words in variable names.

1. Each variable's name should be descriptive of its purpose.

1. Variable names should never be prefixed with their data types.

2. The names of all Boolean variables or Integers containing Boolean information should be phrased as the question they answer. For example, `done_yet` or `is_buffer_full`.


## Functions, Macros and ISR

1. All functions that implement ISRs or are ISR-Safe should be given names ending with `_isr`.

1. All functions that encapsulate threads of execution (a.k.a., tasks, processes) should be given names ending with `_task` (or `_thread`, `_process`).

1. No procedure should have a name that is a keyword of any standard version of the C or C++ programming language. Restricted names include `interrupt`, `inline`, `class`, `true`, `false`, `public`, `private`, `friend`, `protected`, and many others.

1. No procedure should have a name that overlaps a function in the C Standard Library. Examples of such names include `strlen`, `atoi`, and `memset`.

1. No procedure should have a name that begins with an underscore or numbers.

1. No function name should contain any uppercase letters.

1. No macro name should contain any lowercase letters.

1. Underscores should be used to separate words in procedure names.

1. Each procedure's name should be descriptive of its purpose. Note that procedures encapsulate the "actions" of a program and thus benefit from the use of verbs in their names (e.g., `adc_read()`); this "noun-verb" word ordering is recommended. Alternatively, procedures may be named according to the question they answer (e.g., `is_led_on()`).

1. The names of all public functions should be prefixed with their module name and an underscore (e.g., `module_name_read()`).




