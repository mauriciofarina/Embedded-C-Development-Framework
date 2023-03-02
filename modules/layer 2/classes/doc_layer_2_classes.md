# Layer 2 (Classes)



One great advantage of modern programming languages is the build-in support to Object-Oriented Programming. Unfortunately, C is a procedural language that does not include these features. Thankfully, it is possible to replicate some of the core features of OOP in C by following a design guideline called Object-Oriented C. From it, classes inherit the following OOP features: Encapsulation, Inheritance, Interface and Polymorphism. Also, they can be presented into two forms:

- **Interface Classes:** are responsible for enforcing a required signature to methods of classes that implement it.

- **Classes:** are any other type of class. They may inherit interface class or other classes to provide specialized behavior. Every class should provide an initialization (input argument) and instance (output argument) structures that are used by the class constructor method. If another class is inherited, both these structures must contain the respective parent structures, named as `super`, as their initial elements. It is of extremely importance that the inherited class structures be the first element of the child to provide subtyping behavior. Finally, only single inheritance is allowed.

Project classes can be designed as bare-metal or RTOS, while, external classes should always be bare-metal.

If external classes required RTOS functionalities, they should be provided in an abstracted format as arguments of the initialization structure. 

As a NFC, classes should only contain private elements. Therefore, only the class itself can access variables from the object handler directly. Any other external access should, always, be done by getter and setter methods.

The framework Class implementation was created based on the [QuantumLeaps](https://github.com/QuantumLeaps/OOP-in-C) project. This repository contains a extensive documentation of all OOC features.

## Module Files

|      File Type       |         Style         |           Required           |
| :------------------: | :-------------------: | :--------------------------: |
|    Public Header     |     `cls_name.h`      |             Yes              |
|     Source Code      |     `cls_name.c`      |             Yes              |
| Public Types Header  |  `cls_name_types.h`   |              No              |
|    Private Header    | `cls_name_private.h`  |              No              |
|   Internal Header    | `cls_name_internal.h` |              No              |
|   Override Header    | `cls_name_override.c` | Only when Overriding Methods |
| Override Source Code | `cls_name_override.h` | Only when Overriding Methods |
| README Documentation |      `README.md`      |             Yes              |

# Examples
- The [example](examples/heap/) provides memory pool child classes (`heap_1`, `heap_2` and `heap_3`) that inherit the `heap` Interface Class

# Templates

- [Class Template](templates/class/) provides simple Class Template
- [Interface Class Template](templates/interface_class/) provides the template for Interface Classes
- [Child Class Template](templates/child_class) provides the template Classes that inherit a Parent or Interface Class

