# Layer 1 (Interfaces)


There role of interfaces is to provide the necessary prototype functions that may be required by Core Library to access all devices peripherals and MCU-specific functionalities and information. Interface functions should be the only interaction between the two Firmware regions. This ensures functions to be independent and Core Library modules to do not require any Hardware specific knowledge.

## Module Files

|      File Type       |       Style        | Required |
| :------------------: | :----------------: | :------: |
|    Public Header     |    `mid_name.h`    |   Yes    |
| Public Types Header  | `mid_name_types.h` |    No    |
| README Documentation |    `README.md`     |   Yes    |


## Examples

- The [example](interfaces/examples/gpio/) provides a simple GPIO interface

## Templates
- The [template](interfaces/templates/name/) provides the template for all interfaces

