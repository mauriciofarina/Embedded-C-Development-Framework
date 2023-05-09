/**
 * @file lib_filesystem_unix.h
 * @author Mauricio Dall Oglio Farina
 * @brief  Unix File System Library
 */
#ifndef __LIB_FILESYSTEM_UNIX_H__
#define __LIB_FILESYSTEM_UNIX_H__

#ifdef USE_UNIX

#ifndef UNIX_ROOT_PATH
#define UNIX_ROOT_PATH "./" /** Filesystem Root Path (must always end with '/') */
#endif

#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#endif
#endif
