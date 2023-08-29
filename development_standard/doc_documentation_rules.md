# Comments and Code Documentation Rules

1. Each Module and function should be documented in Doxygen comment format.
    
    - The Module Main Header file should contain at least the following information:
        - `@file` Header Filename
        - `@author` Code Author Name and Email
        - `@brief` Module Description

        ```c
        /**
        * @file app_template.h
        * @author Author Name (Developer Email)
        * @brief Application Template
        */
        ```


    - Function prototypes should contain at least the following information:
        - `@brief` Function description
        - `@param` Function argument description
            - `[in]` and `[out]` tags should be used for input and output arguments respectively
        - `@return` Function return value

        ```c
        /**
        * @brief Copy String with Offset
        * 
        * @param str_0[in] Input String
        * @param str_1[out] Output String
        * @param offset[in] Input String Offset
        *
        * @return bool true Success
        * @return bool false Failed
        */
        bool copy_string(const char *str_0, char *str_1, size_t offset) {

            bool error = true;

            size_t in_length = strlen(str_0);

            if (in_length < offset) {
                strcpy(str_1, &str_0[offset]);
                error = false;
            } 

            return error;
        }
        ```

    - Global Variables and Definitions should contain an inline brief description:
        
        ```c
        #define STRING_LENGTH 10 /** String Length */
        const uint32_t str[STRING_LENGTH] = "Hello World"; /** Hello World String */ 
        ```

    - Structures and Enumerators should contain a header `@brief` description and inline item descriptions:
        
        ```c
        /**
        * @brief Foo Struct
        */
        typedef struct {

            uint32_t item_0; /** Item 0 Description */
            uint32_t item_1; /** Item 1 Description */

        } foo_struct_t;

        /**
        * @brief Foo Enum
        */
        typedef enum {

            ITEM_0, /** Item 0 Description */
            ITEM_1, /** Item 1 Description */

        } foo_enum_t;
        ```

    - Macros should contain at least the following information:
        - `@brief` Macro description
        - `@param` Macro argument description
            - `[in]` and `[out]` tags should be used for input and output arguments respectively

        ```c
        /**
        * @brief Copy String with Offset
        * 
        * @param result[out] Sum Result
        * @param a[in] value
        * @param b[in] value
        */
        #define SUM_TWO_NUMBERS(result, a, b) { \
            result = a + b;                     \
            }
        ```

    - Always document all measurement units:

        ```c
        #define TIMEOUT 100 /** Timeout Time (ms) */

        /**
        * @brief Cartesian Coordinate
        */
        typedef struct {
            uint32_t x; /** X Axis (cm) */
            uint32_t y; /** Y Axis (cm) */
        }coordinate_t;
        ```



1. Do not use the traditional C style comments (`/* ... */`), use C++ style instead  (`// ...`)

1. Inline comments should always describe a single line of code. Comments on top of a block of code should describe the block behavior.

    ```c
    // Create Buffer
    uint32_t *buffer = NULL;        // Declare Buffer Pointer
    size_t buffer_size = 10;        // Declare Buffer Size
    buffer = malloc(buffer_size);   // Allocate Buffer on Heap
    ```

1. Comments should never contain the preprocessor tokens `/*`, `//`, or `\`.

1. Committed code should never be commented out, even temporarily. Delete it before committing or use the preprocessor's conditional compilation feature instead. For example:
    
    ```c
    // Some Code...
    #ifdef DEBUG
    printf("Debug Log\n");
    #endif
    // Some Code..
    ```

1. Whenever an algorithm or technical detail is defined in an external reference (e.g., a design specification, patent, or textbook), a comment should include a sufficient reference to the original source to allow a reader of the code to locate the document.

1. All assumptions should be spelled out in comments.

1. All comments should be written in clear and complete sentences, with proper spelling and grammar and appropriate punctuation.

1. Avoid explaining the obvious. Assume the reader knows the C programming language.

1. Use the following capitalized comment markers to highlight important issues:
    - `WARNING:` alerts a maintainer there is risk in changing this code.
    - `NOTE:` provides descriptive comments about the "why" of a chunk of code.
    - `TODO:`  indicates an area of the code is still under construction and explains what remains to be done.
    - `FIXME:` alerts about a non-fixed problem. 
    - `FUTURE:` informs something to be done in the future. 


1. Each project module should provide a `readme.md` file (written in Markdown) containing the complete module's description and documentation. 

1. All external documentation files should be placed inside a `docs` directory inside the respective module directory.
