# Layer 2 (Libraries)

Libraries are single instance components that may cluster a group of other components to implement a system functionality. Besides that, libraries can also be used to abstract third-party libraries or provide multi-thread implementations. 

Library components are presented into three types:

## Libraries: 
They are components that provide higher level functionalities.

## Third-Party Libraries:
They are libraries that are not maintained or developed in-house. Open-source or purchased libraries are examples of this type of library. It is important that these libraries can not be consider part of the component layer itself. Instead, they represent an external layer that exists in parallel to layers 0, 1 and 2.

It is common to see third-party libraries being provided by code generator tools provided by vendors. Therefore, third-party libraries are an exception layer that can exist in both MCU Project and Core Library.

The main disadvantage of using third-party libraries is that they may be limited to a certain domain. For example, a Liquid Crystal Display (LCD) display library may be applicable for only a specific list of display devices. However, it may be necessary to replace the device display with a different unsupported model. Having third-party specific calls inside of the product code would then result in problems. For that reason, every third party should be abstracted by an Interface library.

# Interface Libraries:
They are responsible for combining and standardizing other libraries or third-party libraries into a process flow. Following the previous LCD example, every display library would be added to the generic interface display library, which would provide abstracted display functions. The corresponding library selection can be made by the interface library by run-time implementation or in compile time.

For RTOS projects, the kernel itself should be seen as a third-party library, and, therefore, be abstracted by an interface library. Some vendors already provide kernel abstraction libraries. Unfortunately, these libraries are, usually, architecture specific. To avoid that, RTOS kernel should always be abstracted by an in-house library.

## Module Files

|      File Type       |        Style         | Required |
| :------------------: | :------------------: | :------: |
|    Public Header     |     `lib_name.h`     |   Yes    |
|     Source Code      |     `lib_name.c`     |   Yes    |
| Public Types Header  |  `lib_name_types.h`  |    No    |
|    Private Header    | `lib_name_private.h` |    No    |
| README Documentation |     `README.md`      |   Yes    |

## Examples
FIXME: Implement
- The [Filesystem Example](examples/filesystem/) provides the implementation for third-party file systems interface library
<!-- - The [example](examples/filesystem/) provides the implementation for third-party file systems interface library -->

## Templates
FIXME: Implement
<!-- - The [template](interfaces/templates/name/) provides the template for all Library Components Implementations -->

