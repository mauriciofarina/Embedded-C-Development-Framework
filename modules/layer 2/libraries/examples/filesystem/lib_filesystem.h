/**
 * @file lib_filesystem.h
 * @author Mauricio Dall Oglio Farina
 * @brief File System Interface Library
 */
#ifndef __LIB_FILESYSTEM_H__
#define __LIB_FILESYSTEM_H__

#include <stdbool.h>
#include <stdint.h>

#if defined(USE_LITTLEFS)
#include "littlefs/lib_filesystem_littlefs.h"
#elif defined(USE_UNIX)
#include "unix/lib_filesystem_unix.h"
#else
#error "No Filesystem Selected"
#endif

/**
 * @brief Open File Flags
 */
typedef enum {
    OPEN_FLAG_RDONLY = 0x0001, /** Open for reading only */
    OPEN_FLAG_WRONLY = 0x0002, /** Open for writing only */
    OPEN_FLAG_RDWR = 0x0004,   /** Open for reading and writing */
    OPEN_FLAG_CREAT = 0x0008,  /** Create file if it does not exist */
    OPEN_FLAG_EXCL = 0x0010,   /** Exclusive use flag */
    OPEN_FLAG_TRUNC = 0x0020,  /** Truncate flag */
    OPEN_FLAG_APPEND = 0x0040, /** Set append mode */
} open_flag_t;

/**
 * @brief Seek File Modes
 */
typedef enum {

    SEEK_MODE_SET = 0, /** file offset is set to offset bytes */
    SEEK_MODE_CUR,     /** file offset is set to its current location plus offset */
    SEEK_MODE_END,     /** file offset is set to the size of the file plus offset */

} seek_mode_t;

/**
 * @brief Init Filesystem
 *
 */
void lib_filesystem_init(void);

/**
 * @brief Open Directory
 *
 * @param path[in] Directory Path
 *
 * @return void* Directory Descriptor
 */
void *lib_filesystem_directory_open(const char *path);

/**
 * @brief Close Filesystem
 *
 * @param directory[in] Directory Descriptor
 *
 * @return true Success
 * @return false Failed
 */
bool lib_filesystem_directory_close(void *directory);

/**
 * @brief Read Directory
 *
 * @param directory[in] Directory Descriptor
 * @param filename[out] Next File Name
 *
 * @return true Success
 * @return false End of Directory or Failed
 */
bool lib_filesystem_directory_read(void *directory, char *filename);

/**
 * @brief Open File
 *
 * @param path[in] File Path
 * @param flags[in] Open Flags
 *
 * @return void* File Descriptor
 * @return Failed to Open File
 */
void *lib_filesystem_file_open(const char *path, uint32_t flags);

/**
 * @brief Close File
 *
 * @param file[in] File Descriptor
 *
 * @return true Success
 * @return false Failed
 */
bool lib_filesystem_file_close(void *file);

/**
 * @brief Get File Size
 *
 * @param file[in] File Descriptor
 *
 * @return int32_t File Size (Bytes)
 */
int32_t lib_filesystem_file_size(void *file);

/**
 * @brief Read File
 *
 * @param file[in] File Descriptor
 * @param buffer[out] Read Data
 * @param size[in] Size (Bytes)
 *
 * @return int32_t Bytes Read
 */
int32_t lib_filesystem_file_read(void *file, void *buffer, uint32_t size);

/**
 * @brief Write File
 *
 * @param file[in] File Descriptor
 * @param buffer[in] Write Data
 * @param size[in] Size (Bytes)
 *
 * @return int32_t Bytes Written
 */
int32_t lib_filesystem_file_write(void *file, const void *buffer, uint32_t size);

/**
 * @brief Seek File
 *
 * @param file[in] File Descriptor
 * @param offset[in] Offset (Bytes)
 * @param mode[in] Seek Mode
 *
 * @return int32_t File Cursor Position
 */
int32_t lib_filesystem_file_seek(void *file, uint32_t offset, seek_mode_t mode);

/**
 * @brief Removes a file or directory
 *
 * @note If removing a directory, the directory must be empty
 *
 * @param path[in] File Path
 *
 * @return true Success
 * @return false Failed
 */
bool lib_filesystem_remove(const char *path);

/**
 * @brief Renames a File or Directory
 *
 * @param old_path[in] Current Path
 * @param new_path[in] New Path
 *
 * @return true Success
 * @return false Failed
 */
bool lib_filesystem_rename(const char *old_path, const char *new_path);

/**
 * @brief Format mounted device
 *
 * @return true Success
 * @return false Failed
 */
bool lib_filesystem_format(void);

/**
 * @brief Get Available Space
 *
 * @return uint32_t Available Space (Bytes)
 */
uint32_t lib_filesystem_available_space(void);

#endif