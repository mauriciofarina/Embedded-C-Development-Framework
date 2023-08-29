# Layer 3 (Applications)

Applications are last framework layer and are responsible for the deployment of every system flow. They can be designed as RTOS threads or bare-metal state machines. Ether case, applications can only include modules from layer 2.

A common problem faced by novice developers is the unexpected behavior caused by not take into consideration the implications running code outside RTOS context. For that reason, every Core Library should contain a System application (even for bare-metal projects). It is a special application that should be seen as the "main function" for the project. All system's initializations and starting of other tasks should be done inside of it. This NFC ensures that every developers execute all Core Library code in RTOS environment. Finally, starting the System task should be done by MCU Project and is, strictly, the only framework exception.

## Module Files

|      File Type       |        Style         | Required |
| :------------------: | :------------------: | :------: |
|    Public Header     |     `app_name.h`     |   Yes    |
|     Source Code      |     `app_name.c`     |   Yes    |
| Public Types Header  |  `app_name_types.h`  |    No    |
|    Private Header    | `app_name_private.h` |    No    |
| README Documentation |     `README.md`      |   Yes    |


## Templates
- The [template](apps/templates/name/) provides the template for all Application Implementations


