# Formatting and Indentation Rules

1. Braces should always surround the blocks of code, following `if`, `else`, `switch`, `while`, `do`, and `for` statements. Single statements and empty statements following these keywords should also always be surrounded by braces. 

1. Each indentation level should align at a multiple of 4 characters from the start of the line.

1. The tab character (ASCII `0x09`) should never appear within any source code file. Use 4 spaces instead (Automate your code editor!).

1. There is no characters per line limit, however whenever is possible try to stay below 100 characters.

1. Whenever a line of code is too long to fit within the maximum line width, indent the second and any subsequent lines in the most readable manner possible.

1. All source code lines should end only with the single character `LF` (ASCII `0x0A`), not with the pair `CR-LF` (`0x0D` `0x0A`).

1. Left Braces (`{`) should always be on the same line of its statement:

    ```c
    // Do This:
    if(x > 0) {
        // Some Code..
    }

    // Not This:
    if(x > 0)
    {
       // Some Code..
    }
    ```

1. Within a `switch` statement, the case labels should be aligned; the contents of each case block should be indented once from there.

## White Space Rules

1. The left brace (`{`) on each `if`, `while`, `for` and `switch` should be separated by one space:

    ```c
    if(x > 0) {
        while(1) {
        }
    }
    ```

1. Each of the assignment operators `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `~=`, and `!=` should always be preceded and followed by one space.

    ```c
    x += 1;
    ```
    

1. Each of the binary operators `+`, `-`, `*`, `/`, `%`, `<`, `<=`, `>`, `>=`, `==`,`!=`, `<<`, `>>`, `&`, `|`, `^`, `&&`, and `||` should always be preceded and followed by one space.
    
    ```c
    if(x != 0)
    ```

1. Each of the unary operators `+`, `-`, `++`, `--`, `!` , and `~`, should be written without a
space on the operand side.

    ```c
    x++;
    ```

1. The pointer operators `*` and `&` should be written without a space on the operand side.

    ```c
    uint32_t *ptr = &var:
    ```

1. The structure pointer and structure member operators (`->` and `.`, respectively) should always be without surrounding spaces.

    ```c
    x = the_pointer->x;
    y = the_struct.y;
    ```

1. The left and right brackets of the array subscript operator (`[` and `]`) should be without surrounding spaces, except as required by another white space rule.

    ```c
    uint32_t x[10];
    ```

1. Expressions within parentheses should always have no spaces adjacent to the left and right parenthesis characters.

    ```c
    x = (a + b);
    ```

1. The left and right parentheses of the function call operator should always be without surrounding spaces. Except when at the end of a line, each comma separating function parameters should always be followed by one space.

    ```c
    void foo(uint32_t a, uint32_t b);
    ```

1. Each semicolon separating the elements of a `for` statement should always be followed by one space.

    ```c
    for(i = 0 ; i < 10 ; ++i) {
    }
    ```

1. Each semicolon should follow the statement it terminates without a preceding
space.

    ```c
    uint32_t x = 1; // Good
    uint32_t x = 1 ; // Bad
    ```