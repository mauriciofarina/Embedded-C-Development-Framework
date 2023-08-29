# Operations Rules

1. **(NFC)** Do not rely on C's operator precedence rules, use parentheses to ensure proper execution order within a sequence of operations. Statements with only addition and subtraction operations are an exception.

    ```c
    x = a/b/c; // Bad
    x = (a/b)/c; // Good

    x = a*b + c; // Bad
    x = (a*b) + c; // Good

    x = a + b + c - d; // This is acceptable
    ```

1. Unless it is a single identifier or constant, each operand of the logical AND (`&&`) and logical OR (`||`) operators should be surrounded by parentheses.

    ```c
    // Do this:
    if ((x >= 0) && (x <= 100)) {
        // Some Code..
    }

    // Do not do this:
    if (x >= 0 && x <= 100) {
        // Some Code..
    }
    ```

1. **(NFC)** Every non-constant division should be protected to avoid zero divisions.

```c
// Unsafe
uint32_t foo(uint32_t a, uint32_t b){
    return (a / b);
}

// Safe
uint32_t foo(uint32_t a, uint32_t b){
    assert(b != 0);
    return (a / b);
}

// Safe
uint32_t foo(uint32_t a, uint32_t b){
    
    uint32_t value = 0;

    if(b != 0){
        value = (a / b);
    }

    return value;
}

```