# General Rules

1. **(NFC)** Do not use `auto`, `register`, `restrict` and `continue` keywords.

1. **(NFC)** C Standard Library functions `abort()`, `exit()`, `setjmp()`, and `longjmp()` should not be used.

1. Do not use ternary expressions (`(a > b) ? 10 : 20`).

1. No line of code should contain more than one statement.

1. Unintended behavior should be protected with `assert()`.

1. Avoid repeating blocks of code (copy and paste code). Code blocks should never be repeated more than once (create a new function instead).

1. Jumps (`goto`) should always respect code flow:

    ```c
    // Good
    bool good(void) {

        bool result = false;

        if(do_something_0()) {
            goto end;
        }

        if(do_something_1()) {
            goto end;
        }

        result = true;

    end:
          return result;
    }

    // Bad
    void bad(void){

    loop_back:
        
        uint32_t value = do_something();
        
        if(value > 10){
            goto loop_back;
        }

    }
    ```


