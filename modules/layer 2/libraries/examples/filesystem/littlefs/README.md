# LittleFS File System Library

LittleFS File System Configuration Library


## Configurations

### Required Preprocessor Macros

|     Macro      |                          Value                           |           Description           |
| :------------: | :------------------------------------------------------: | :-----------------------------: |
| `USE_LITTLEFS` |                                                          |  Enables LittleFS File System   |
|  `LFS_CONFIG`  | `filesystem/littlefs/lfs_config.h` **(Do Not Use `""`)** | Overrides LittleFS `lfs_util.h` |


### Library Configuration

|                     Macro                      |           Description           |
| :--------------------------------------------: | :-----------------------------: |
|               `USE_RTOS_KERNEL`                | Only Required for RTOS Projects |
|      `LIB_FILESYSTEM_LITTLEFS_HEAP_SIZE`       |    Heap Size (64 bit Items)     |
| `LIB_FILESYSTEM_LITTLEFS_HEAP_MAX_ALLOCATIONS` | Max Number of Heap Allocations  |


### LittleFS

|      Macro       |                       Description                       |
| :--------------: | :-----------------------------------------------------: |
| `LFS_YES_TRACE`  |                    Enable Trace Logs                    |
|  `LFS_NO_DEBUG`  |                   Disable Debug Logs                    |
|  `LFS_NO_WARN`   |                  Disable Warning Logs                   |
|  `LFS_NO_ERROR`  |                   Disable Error Logs                    |
|  `LFS_NAME_MAX`  |                   Max Filename Length                   |
| `LFS_THREADSAFE` | Enable Thread-Safe Mode (Required if `USE_RTOS_KERNEL`) |
|  `LFS_NAME_MAX`  |            Set Filename Max Character length            |


### Memory Implementations

|             Macro             |      Description      |
| :---------------------------: | :-------------------: |
| `USE_LITTLEFS_FLASH_EMULATOR` |  Use Flash Emulator   |
|    `USE_DEVICE_AT45DB161E`    | Use AT45DB161E Device |
|    `USE_DEVICE_AT45DB641E`    | Use AT45DB641E Device |





# Development Guidelines

## LittleFS `lfs_util.h`

LittleFS allows that overriding the `lfs_util.h` file. We do this to provide our own heap implementation to the library.

## memories folder

Every memory peripheral should implement the required interface functions provided by `lib_filesystem_littlefs_private.h`. 






