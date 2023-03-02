# Layer 2 (Devices)

Devices are components that represent Integrated Circuit (IC) peripherals and should always be external components. To allow the increase of their use domain, it is also expected that device implementations be bare-metal and allow multiple instances. Every device should provide a handler variable type with all information regarding a single instance. To operate devices, it is expected that this handler be passed as the first function argument, excusing the need of instance specific implementations. 

## Module Files

|      File Type       |         Style         | Required |
| :------------------: | :-------------------: | :------: |
|    Public Header     |     `dev_name.h`      |   Yes    |
|     Source Code      |     `dev_name.c`      |   Yes    |
| Public Types Header  |  `dev_name_types.h`   |    No    |
|    Private Header    | `dev_name_private.h`  |    No    |
|   Internal Header    | `dev_name_internal.h` |    No    |
| README Documentation |      `README.md`      |   Yes    |

## Examples

- The [example](examples/mbi5025/) provides the implementation for the MBI5025 IC

## Templates
- The [template](interfaces/templates/name/) provides the template for all Device Components Implementations

