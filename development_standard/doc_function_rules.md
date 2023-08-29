# Function Rules

1. The `static` keyword should be used to declare all functions that do not need to be visible outside the file where were declared.

1. It is a preferred practice that all functions should have just one exit point and it should be via a `return` at the bottom of the function.

1. **(NFC)** The returning variable should always be placed as function's first line of code.
   
1. **(NFC)** It is a preferred practice that all returning variables be initiated with fail/`false`/`0` values. For example:

```c
bool foo(uint32_t a, uint32_t b) {

    bool result = false;

    if ((0 == a) && (0 == b)) {
        result = true;
    }

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