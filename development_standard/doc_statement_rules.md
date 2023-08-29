# Statement Rules

1. Nested `if`/`else` statements should not be deeper than two levels. Use function calls or `switch` statements to reduce complexity and aid understanding.

1. Assignments should not be made within an `if` or `else if` test.

1. **(NFC)** When evaluating the equality of a variable against a constant, the constant should always be placed to the left of the equal-to operator (`==`). This avoid problems where a missing `=` may still result in a valid operation. For Example:

    ```c
    uint32_t x = 10;

    // The developer missed an = in this comparison
    // However, the operation is still valid but the
    // comparison will be incorrect.
    if(x = 100) {
        printf("Success\n");
    }else {
        printf("Fail\n");
    }
    ```

    For that reason, always prefer:

    ```c
    uint32_t x = 10;

    if(100 == x) {
        printf("Success\n");
    }else {
        printf("Fail\n");
    }
    ```

    If the developer misses an `=`, the expression will become invalid and the compiler will accuse an error.

1. All `switch` statements should contain a `default` block.

1. Any `case` designed to fall through to the next should be commented to clearly explain the absence of the corresponding `break`.

1. Magic numbers should not be used as the initial value or in the endpoint test of a `while`, `do`…`while`, or `for` loop.

1.  With the exception of the initialization of a loop counter in the first clause of a `for` statement and the change to the same variable in the third, no assignment should be made in any loop's controlling expression.

1.  Infinite loops should be implemented via controlling expression `for(;;)`.

1. **(NFC)** Each loop with an empty body should feature a set of braces enclosing a comment to explain why nothing needs to be done until after the loop terminates.

1. Decremental to `0 ` `for` loops are usually more efficient than Incremental. Also, prefix operations (`--` and `++`) are more efficient than postfix.

    ```c
    for(uint32_t i = 0 ; i < 100 ; i++);    // Slowest
    for(uint32_t i = 0 ; i < 100 ; ++i);    // Slow
    for(uint32_t i = 100 ; i > 0 ; i--);    // Fast
    for(uint32_t i = 100 ; i > 0 ; --i);    // Faster
    for(uint32_t i = 100 ; i != 0 ; --i);    // Fastest
    ```

