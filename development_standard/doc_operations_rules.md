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