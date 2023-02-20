# Novice Framework Choices (NFC)

Novice developers may introduce problems to the system or violate the design choices made by the system architect. To address that the framework provides conventions called Novice Framework Choice (NFC) to guide these developers and prevent their most common mistakes.

## **Variable Initialization**

Variables should **Always** be initialized. This will avoid issues such as:

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

## **Return Variable**

Unless Single-Lined, the returning value should always be declared as the function's first line of code. Also, every function should only contain a single `return` as the last line of code.

```c
uint32_t foo(void) {
    
    uint32_t value = 0; //Always first line of code

    //...

      if (b != 0) {
        value = (a / b);
    }

    //...


    return value; //Always last line of code
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

## **Default Returning Value**

It is preferable that the `return` variable be initialized with a "fail" value. This allows functions to only result in success after conditions are met. For example:

```c
bool foo(uint32_t a, uint32_t b) {

    bool result = false;

    if (a < 10){
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

## **Zero Division**

Every non-constant division should be protected to avoid zero divisions.

```c
//Bad
uint32_t foo(uint32_t a, uint32_t b){
    return (a / b);
}
//Good
uint32_t foo(uint32_t a, uint32_t b){
    assert(b != 0);
    return (a / b);
}
//Good
uint32_t foo(uint32_t a, uint32_t b){
    
    uint32_t value = 0;

    if(b != 0){
        value = (a / b);
    }

    return value;
}

```