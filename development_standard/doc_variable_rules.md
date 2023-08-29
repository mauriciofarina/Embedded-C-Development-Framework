# Variable Rules

1. **(NFC)** All variables should be initialized before use. This will avoid issues such as:

    ```c
    // Will return unknown/trash value if (a <= b)
    uint32_t foo(uint32_t a, uint32_t b) {
    
        uint32_t value;
    
        if (a > b) {
            value = (a + b);
        }
    
        return value;
    }
    ```

1. **(NFC)** It is always preferable to initialize variables on declaration.

1. It is preferable to define local variables as you need them, rather than all at the top of a function.

1. If global variables are used, their definitions should be grouped together and placed at the top of a source code file.

1. **(NFC)** Any pointer variable lacking an initial address should be initialized to `NULL`.

1. The comma operator (`,`) should not be used within variable declarations.

1. The `static` keyword should be used to declare all global variables that do not need to be visible outside the file where were declared.

1. The `const` keyword should be used whenever appropriate. Examples include:
    - To declare variables that should not be changed after initialization;
    - To define call-by-reference function parameters that should not be modified (e.g., `const char *param`);
    - To define fields in a `struct` or `union` that should not be modified (e.g., in a `struct` overlay for memory-mapped I/O peripheral registers);
    - As a strongly typed alternative to `#define` for numerical constants.

1. The `volatile` keyword should be used whenever appropriate. Examples include:
    - To declare a global variable accessible (by current use or scope) by any interrupt service routine;
    - To declare a global variable accessible (by current use or scope) by two or more threads;
    - To declare a pointer to a memory-mapped I/O peripheral register set (e.g., `const volatile timer_t *timer`);
    - To declare a delay loop counter/spin-lock.

1. The order: `static`, `volatile`, `const` and data-type, should be respected.

1. Each unsafe cast should feature an associated comment describing how the code ensures proper behavior across the range of possible values on the right side.

    ```c
    uint32_t byte_value = 128;

    uint8_t byte = (uint8_t)byte_value; // Limits value range to 8 bit values

    ```

## Structures, Unions, Enumerates

1. **(NFC)** Appropriate care should be taken to prevent the compiler from inserting padding bytes within `struct` or `union` types. Special attention should be given to these types when used to (but not restricted to):
    - communicate with peripherals
    - communicate over a bus or network
    - communicate with another processor
    - casting data arrays to a given type pointer
  
    In such cases unused spaces should be explicit declared by the developer.

    ```c
    // For a 32 bit processor, this struct will consume 12 Bytes of memory.
    typedef struct {
        uint8_t  b;
        uint32_t c;
        uint16_t a;
    } foo_t;

    // Whenever relevant, padding should be avoided as in the example below
    typedef struct {
        uint8_t  b;
        uint8_t not_used_0[3];
        uint32_t c;
        uint16_t a;
        uint8_t not_used_1[2];
    } foo_t;
    ```

    Also, compiler modifiers should not be used to solve this problem.

1. Appropriate care should be taken to prevent the compiler from altering the intended order of the bits within bit-fields (even if unused, declare variables that sum the total number of bit of the used data type).

1. Bit-fields should not be defined within `signed` integer types.


## Fixed-Width Integers

1. Do not use `char`, `short`, `int`, `long`, or `long long` for integer values. Use the `stdint.h` data types `int8_t`, `uint8_t`, `int16_t`, `uint16_t`, `int32_t`, `uint32_t`, `int64_t` or `uint64_t` instead.

1. The `char` type is should be restricted to the declaration of an operations concerning strings.

1. None of the bitwise operators (i.e., `&`, `|`, `~`, `^`, `<<`, and `>>`) should be used to manipulate `signed` integer data.

1. `signed` integers should not be combined with `unsigned` integers in comparisons or expressions. 

1. Always prefer using data types with the size of your processor architecture.

1. Whenever a third-party library expect the data types `char`, `short`, `int`, `long`, or `long long` as fixed-width integers, all developed code should comply with `stdint.h` data types and, on library function call, be explicit casted to the respective data type. Variable checks should be made to ensure that variables are equivalent (e.g., use `sizeof(int)`).   

## Booleans

1. Boolean variables should be declared as type `bool` defined in `stdbool.h`.

## Floating Point

1. **(NFC)** Avoid the use of floating point constants and variables whenever possible. Fixed-point math may be an alternative.

1. When floating point calculations are necessary:
    - Do not use the `float` and `double` types. Use instead the C99 type names `float32_t`, `float64_t`, and `float128_t`.
    - Append an `f` to all single-precision constants (e.g., `pi = 3.141592f`).
    - Ensure that the compiler supports double precision, if your math depends on it.
    - Never test for equality (`==`) or inequality (`!=`) of floating point values.
    - Always invoke the `isfinite()` macro to check that prior calculations have resulted in neither `INFINITY` nor `NaN`.




