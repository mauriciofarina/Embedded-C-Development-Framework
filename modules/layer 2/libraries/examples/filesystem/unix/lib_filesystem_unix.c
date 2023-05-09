/**
 * @file lib_filesystem_unix.c
 * @author Mauricio Dall Oglio Farina
 * @brief Unix FileSystem Library
 */
#ifdef USE_UNIX
#include "lib_filesystem_unix.h"

#include "filesystem/lib_filesystem.h"

/**
 * @brief Convert Project Path into Unix Path
 *
 * @param path[in] System Path
 * @param unix_path[out] Unix Path
 */
static inline void set_unix_path(const char *path, char *unix_path) {
    char root[] = UNIX_ROOT_PATH;
    sprintf(unix_path, "%s%s", root, path);
}

void lib_filesystem_init(void) {
}

void *lib_filesystem_directory_open(const char *path) {
    void *descriptor = NULL;
    assert(0); // Not Implemented
    return descriptor;
}

bool lib_filesystem_directory_close(void *directory) {
    bool result = false;
    assert(0); // Not Implemented
    return result;
}

bool lib_filesystem_directory_read(void *directory, char *filename) {
    bool result = false;
    assert(0); // Not Implemented
    return result;
}

void *lib_filesystem_file_open(const char *path, uint32_t flags) {

    int file = -1;

    int unix_flags = 0;

    if (flags & OPEN_FLAG_RDONLY) {
        unix_flags |= O_RDONLY;
    }
    if (flags & OPEN_FLAG_WRONLY) {
        unix_flags |= O_WRONLY;
    }
    if (flags & OPEN_FLAG_RDWR) {
        unix_flags |= O_RDWR;
    }
    if (flags & OPEN_FLAG_CREAT) {
        unix_flags |= O_CREAT;
    }
    if (flags & OPEN_FLAG_EXCL) {
        unix_flags |= O_EXCL;
    }
    if (flags & OPEN_FLAG_TRUNC) {
        unix_flags |= O_TRUNC;
    }
    if (flags & OPEN_FLAG_APPEND) {
        unix_flags |= O_APPEND;
    }

    char unix_path[128] = {0};
    set_unix_path(path, unix_path);

    file = open(unix_path, unix_flags);

    assert(file != 0); // Should never be 0
    if (file < 0) {
        file = 0;
    }

    return (void *)file;
}

bool lib_filesystem_file_close(void *file) {

    bool result = false;

    if (0 == close((int)file)) {
        result = true;
    }

    return result;
}

int32_t lib_filesystem_file_size(void *file) {

    off_t size = lseek((int)file, 0, SEEK_END);

    return (int32_t)size;
}

int32_t lib_filesystem_file_read(void *file, void *buffer, uint32_t size) {

    int32_t bytes_read = (int32_t)read((int)file, buffer, (size_t)size);

    return bytes_read;
}

int32_t lib_filesystem_file_write(void *file, const void *buffer, uint32_t size) {

    int32_t bytes_written = (int32_t)write((int)file, buffer, (size_t)size);

    return bytes_written;
}

int32_t lib_filesystem_file_seek(void *file, uint32_t offset, seek_mode_t mode) {

    int32_t index = 0;

    switch (mode) {
        case SEEK_MODE_SET:
            index = (int32_t)lseek((int)file, (off_t)offset, SEEK_SET);
            break;
        case SEEK_MODE_CUR:
            index = (int32_t)lseek((int)file, (off_t)offset, SEEK_CUR);
            break;
        case SEEK_MODE_END:
            index = (int32_t)lseek((int)file, (off_t)offset, SEEK_END);
            break;
        default:
            assert(0);
            break;
    }
    return index;
}

bool lib_filesystem_remove(const char *path) {

    bool result = false;
    assert(0); // Not Implemented
    return result;
}

bool lib_filesystem_rename(const char *old_path, const char *new_path) {

    bool result = false;
    assert(0); // Not Implemented
    return result;
}

bool lib_filesystem_format(void) {

    bool result = false;
    assert(0); // Not Implemented
    return result;
}

uint32_t lib_filesystem_available_space(void) {

    uint32_t available_space = 0;
    assert(0); // Not Implemented
    return available_space;
}

void *lib_filesystem_directory_open(const char *path) {
    return opendir(path);
}

bool lib_filesystem_directory_close(void *directory) {
    return !(bool)closedir(directory);
}

bool lib_filesystem_directory_read(void *directory, char *filename) {

    bool result = false;

    struct dirent *file_info = readdir(directory);
    if (file_info != NULL) {
        strcpy(filename, file_info->d_name);
        result = true;
    }

    return result;
}

#endif
