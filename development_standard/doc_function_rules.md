# Function Rules

1. The `static` keyword should be used to declare all functions that do not need to be visible outside the file where were declared.


1. **(NFC)** Unless Single-Lined, the returning value should always be declared as the function's first line of code. Also, every function should only contain a single exit point (`return`) at the bottom of the function.

    ```c
    uint32_t foo(void) {

        uint32_t value = 0; // Always first line of code

        if (b != 0) {
            value = (a / b);
        }

        return value; // Always last line of code
    }
    ```

    This will avoid issues where returning values may be undefined on not present. For example:

    ```c
    // Will Never return if (a == b)
    uint32_t foo(uint32_t a, uint32_t b) {

        if (a < b) {
            return 10;
        }else if (a > b) {
            return 20;
        }

    }

    // Will Never return if SOME_TAG is not defined
    uint32_t foo(uint32_t a, uint32_t b) {
    #ifdef SOME_TAG
        return (a + b);
    #endif
    }
    ```
   
1. **(NFC)** It is a preferred practice that all returning variables be initiated with fail/`false`/`0` values. This allows functions to only result in success after conditions are met. For example:

    ```c
    bool foo(uint32_t a, uint32_t b) {

        bool result = false;

        if (a < 10) {
            goto end;
        }

        if (b > 200) {
            goto end;
        }

        if (a != b) {
            result = (a < b); // Will only process the result here
        }

    end:
        return result;
    }
    ```

1. A prototype should be declared for each public function in their respective header file.

1. A prototype should be declared for each private function in their respective private header file.

1. Whenever possible, all private functions should be declared `static`.

1. Each parameter should be explicitly declared and meaningfully named. 

1. Always prefer passing `struct` variables by reference. 

1. Functions that `return` `float` or `double` types should always have a prototype (The compiler will consider an integer `return` type otherwise).

1. To ensure that ISRs are not inadvertently called from other parts of the software (they may corrupt the CPU and call stack if this happens), each ISR function should be declared `static`.

1. A stub or default ISR should be installed in the vector table at the location of all unexpected or otherwise unhandled interrupt sources. Each such stub could attempt to disable future interrupts of the same type, say at the interrupt controller, and `assert`.