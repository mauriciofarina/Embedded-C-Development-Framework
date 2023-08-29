# Preprocessors Rules

1. Preprocessor directive `#define` should not be used to alter or rename any keyword or other aspect of the programming language. For example:

    ```c
    // Do not do this...
    #define begin { 
    #define end }
    
    for (int row = 0; row < MAX_ROWS; row++)
    begin
    // Loop Code...
    end
    ```

1. **(NFC)** Parameterized macros should not be used if a function can be written to accomplish the same behavior. Use `inline` functions instead.

1. If parameterized macros are used for some reason, these rules apply:
    - Surround the entire macro body with parentheses.
    - Surround each use of a parameter with parentheses.
    - Never include a transfer of control (e.g., `return` keyword).

    ```c
    #define MAX(A, B) ((A) > (B) ? (A) : (B)) // You still should not use ternary. It was used here just for simplicity.
    ```
