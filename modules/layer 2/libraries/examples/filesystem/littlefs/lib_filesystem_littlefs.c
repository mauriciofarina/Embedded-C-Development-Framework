/**
 * @file lib_filesystem_littlefs.c
 * @author Mauricio Dall Oglio Farina
 * @brief LittleFS FileSystem Library
 */
#ifdef USE_LITTLEFS
#include "lib_filesystem_littlefs.h"
#include "lib_filesystem_littlefs_private.h"

#include "lfs_config.h"

#include "filesystem/lib_filesystem.h"

#ifdef USE_RTOS_KERNEL
static rtos_mutex_t littlefs_mutex = {0};   /** LittleFS Mutex */
static rtos_mutex_t filesystem_mutex = {0}; /** File System Mutex */
#endif

static struct lfs_config config = {0};                               /** LittleFS Configuration */
static lfs_t file_system = {0};                                      /** LittleFS File System */

static bool directory_descriptor_on_use[MAX_OPEN_DIRECTORIES] = {0}; /** Directory Descriptor On Use */
static lfs_dir_t directory_descriptor[MAX_OPEN_DIRECTORIES] = {0};   /** Directory Descriptor */

static bool file_descriptor_on_use[MAX_OPEN_FILES] = {0};            /** File Descriptor On Use */
static lfs_file_t file_descriptor[MAX_OPEN_FILES] = {0};             /** File Descriptor */

#ifdef USE_RTOS_KERNEL
#define FILESYSTEM_LOCK()   cls_rtos_mutex_lock_default(&filesystem_mutex)
#define FILESYSTEM_UNLOCK() cls_rtos_mutex_unlock(&filesystem_mutex)
#else
#define FILESYSTEM_LOCK()   true
#define FILESYSTEM_UNLOCK() (void)NULL
#endif

/**
 * @brief LittleFS Lock
 *
 * @return LFS_ERR_OK Lock Successful
 * @return LFS_ERR_IO Lock Failed
 */
static inline int lock(const struct lfs_config *c) {
    (void)c;
#ifdef USE_RTOS_KERNEL
    return !cls_rtos_mutex_lock_default(&littlefs_mutex);
#else
    return false;
#endif
}

/**
 * @brief LittleFS Unlock
 *
 * @return LFS_ERR_OK Unlock Successful
 * @return LFS_ERR_IO Unlock Failed
 */
static inline int unlock(const struct lfs_config *c) {
    (void)c;
#ifdef USE_RTOS_KERNEL
    cls_rtos_mutex_unlock(&littlefs_mutex);
#endif

    return LFS_ERR_OK;
}

void lib_filesystem_init(void) {

#ifdef USE_RTOS_KERNEL
    cls_rtos_mutex_init(&littlefs_mutex);
    cls_rtos_mutex_init(&filesystem_mutex);
#endif

    lfs_config_init();    // Init Memory Management
    memory_device_init(); // Init Device

    config.read = littlefs_read;
    config.prog = littlefs_prog;
    config.erase = littlefs_erase;
    config.sync = littlefs_sync;

    config.read_size = get_device_read_size();
    config.prog_size = get_device_write_size();
    config.block_size = get_device_block_size();
    config.block_count = get_device_number_of_pages();
    config.cache_size = get_device_cache_size();
    config.block_cycles = DEFAULT_BLOCK_CYCLES;
    config.lookahead_size = DEFAULT_LOOKAHEAD_SIZE;

#ifdef USE_RTOS_KERNEL
    config.lock = lock;
    config.unlock = unlock;
#endif

    // mount the filesystem
    int error = lfs_mount(&file_system, &config);

    // reformat if we can't mount the filesystem
    // this should only happen on the first boot
    if (error) {
        assert(!lfs_format(&file_system, &config));
        assert(!lfs_mount(&file_system, &config));
    }
}

void *lib_filesystem_directory_open(const char *path) {

    lfs_dir_t *directory = NULL;

    if (FILESYSTEM_LOCK()) {

        for (uint32_t i = 0; i < MAX_OPEN_DIRECTORIES; ++i) {
            if (!directory_descriptor_on_use[i]) {

                if (LFS_ERR_OK == lfs_dir_open(&file_system, &directory_descriptor[i], path)) {
                    directory = &directory_descriptor[i];
                    directory_descriptor_on_use[i] = true;
                }
                break;
            }
        }

        FILESYSTEM_UNLOCK();
    }

    return directory;
}

bool lib_filesystem_directory_close(void *directory) {

    bool result = false;

    int32_t index = -1;

    if (FILESYSTEM_LOCK()) {

        for (int32_t i = 0; i < MAX_OPEN_DIRECTORIES; ++i) {
            if (&directory_descriptor[i] == directory) {
                index = i;
                break;
            }
        }

        if (index >= 0) {

            if (LFS_ERR_OK == lfs_dir_close(&file_system, directory)) {
                result = true;
                directory_descriptor_on_use[index] = false;
                memset(&directory_descriptor[index], 0, sizeof(lfs_dir_t));
            }
        }

        FILESYSTEM_UNLOCK();
    }

    return result;
}

bool lib_filesystem_directory_read(void *directory, char *filename) {

    bool result = false;

    struct lfs_info info = {0};

    if (FILESYSTEM_LOCK()) {

        if (LFS_ERR_OK < lfs_dir_read(&file_system, directory, &info)) {
            strcpy(filename, info.name);
            result = true;
        }

        FILESYSTEM_UNLOCK();
    }

    return result;
}

void *lib_filesystem_file_open(const char *path, uint32_t flags) {

    lfs_file_t *file = NULL;

    // Convert LittleFS Flags to <fcntl.h> Flags
    uint32_t littlefs_flag = 0;

    if (flags & OPEN_FLAG_RDONLY) {
        littlefs_flag |= LFS_O_RDONLY;
    }
    if (flags & OPEN_FLAG_WRONLY) {
        littlefs_flag |= LFS_O_WRONLY;
    }
    if (flags & OPEN_FLAG_RDWR) {
        littlefs_flag |= LFS_O_RDWR;
    }
    if (flags & OPEN_FLAG_CREAT) {
        littlefs_flag |= LFS_O_CREAT;
    }
    if (flags & OPEN_FLAG_EXCL) {
        littlefs_flag |= LFS_O_EXCL;
    }
    if (flags & OPEN_FLAG_TRUNC) {
        littlefs_flag |= LFS_O_TRUNC;
    }
    if (flags & OPEN_FLAG_APPEND) {
        littlefs_flag |= LFS_O_APPEND;
    }

    if (FILESYSTEM_LOCK()) {

        for (uint32_t i = 0; i < MAX_OPEN_FILES; ++i) {
            if (!file_descriptor_on_use[i]) {

                if (LFS_ERR_OK == lfs_file_open(&file_system, &file_descriptor[i], path, littlefs_flag)) {
                    file = &file_descriptor[i];
                    file_descriptor_on_use[i] = true;
                }
                break;
            }
        }

        FILESYSTEM_UNLOCK();
    }

    return file;
}

bool lib_filesystem_file_close(void *file) {

    bool result = false;

    int32_t index = -1;

    if (FILESYSTEM_LOCK()) {

        for (int32_t i = 0; i < MAX_OPEN_FILES; ++i) {
            if (&file_descriptor[i] == file) {
                index = i;
                break;
            }
        }

        if (index >= 0) {

            if (LFS_ERR_OK == lfs_file_close(&file_system, file)) {
                result = true;
                file_descriptor_on_use[index] = false;
                memset(&file_descriptor[index], 0, sizeof(lfs_file_t));
            }
        }

        FILESYSTEM_UNLOCK();
    }

    return result;
}

int32_t lib_filesystem_file_size(void *file) {

    int32_t size = 0;
    if (FILESYSTEM_LOCK()) {
        size = lfs_file_size(&file_system, file);
        FILESYSTEM_UNLOCK();
    }
    return size;
}

int32_t lib_filesystem_file_read(void *file, void *buffer, uint32_t size) {

    int32_t bytes_read = 0;
    if (FILESYSTEM_LOCK()) {
        bytes_read = lfs_file_read(&file_system, file, buffer, size);
        FILESYSTEM_UNLOCK();
    }
    return bytes_read;
}

int32_t lib_filesystem_file_write(void *file, const void *buffer, uint32_t size) {

    int32_t bytes_written = 0;
    if (FILESYSTEM_LOCK()) {
        bytes_written = lfs_file_write(&file_system, file, buffer, size);
        FILESYSTEM_UNLOCK();
    }
    return bytes_written;
}

int32_t lib_filesystem_file_seek(void *file, uint32_t offset, seek_mode_t mode) {

    int32_t index = 0;
    if (FILESYSTEM_LOCK()) {
        index = lfs_file_seek(&file_system, file, offset, mode);
        FILESYSTEM_UNLOCK();
    }
    return index;
}

bool lib_filesystem_remove(const char *path) {

    bool result = false;

    if (FILESYSTEM_LOCK()) {
        if (lfs_remove(&file_system, path) >= 0) {
            result = true;
        }
        FILESYSTEM_UNLOCK();
    }

    return result;
}

bool lib_filesystem_rename(const char *old_path, const char *new_path) {

    bool result = false;

    if (FILESYSTEM_LOCK()) {
        if (lfs_rename(&file_system, old_path, new_path) >= 0) {
            result = true;
        }
        FILESYSTEM_UNLOCK();
    }

    return result;
}

bool lib_filesystem_format(void) {

    bool result = false;

    if (FILESYSTEM_LOCK()) {
        assert(!lfs_unmount(&file_system));
        if (lfs_format(&file_system, &config) >= 0) {
            assert(!lfs_mount(&file_system, &config));
            result = true;
        }
        FILESYSTEM_UNLOCK();
    }

    return result;
}

uint32_t lib_filesystem_available_space(void) {

    uint32_t available_space = 0;
    if (FILESYSTEM_LOCK()) {
        int32_t used_space = lfs_fs_size(&file_system);

        if (0 > used_space) {
            used_space = 0;
        }

        used_space *= config.block_size;

        uint32_t total_space = (config.block_size * config.block_count);

        available_space = total_space - used_space;
        FILESYSTEM_UNLOCK();
    }

    return available_space;
}

#endif
