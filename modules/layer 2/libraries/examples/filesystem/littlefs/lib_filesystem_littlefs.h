/**
 * @file lib_filesystem_littlefs.h
 * @author Mauricio Dall Oglio Farina
 * @brief  LittleFS FileSystem Library
 */
#ifndef __LIB_FILESYSTEM_LITTLEFS_H__
#define __LIB_FILESYSTEM_LITTLEFS_H__

#ifdef USE_LITTLEFS

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#if defined(USE_DEVICE_AT45DB161E)
#include "at45db161e/dev_at45db161e_types.h"
#elif defined(USE_DEVICE_AT45DB641E)
#include "at45db641e/dev_at45db641e_types.h"
#elif defined(USE_LITTLEFS_FLASH_EMULATOR)
#else
#error "No External Flash Device Selected for LittleFS"
#endif

// LittleFS Third-Party Library Configurations

#include "LittleFS/lfs.h"
#if ((LFS_VERSION_MAJOR != 2) && (LFS_VERSION_MINOR != 5))
#error "Invalid LittleFS Version"
#endif

#ifndef DEFAULT_LOOKAHEAD_SIZE
#define DEFAULT_LOOKAHEAD_SIZE (8 * 8) /** Default Lookahead Size Value */
#endif

#ifndef DEFAULT_BLOCK_CYCLES
#define DEFAULT_BLOCK_CYCLES 500 /** Default Block Cycles Value */
#endif

#ifndef MAX_OPEN_DIRECTORIES
#define MAX_OPEN_DIRECTORIES 1 /** Max Number of Open Directories */
#endif

#ifndef MAX_OPEN_FILES
#define MAX_OPEN_FILES 3 /** Max Number of Open Files */
#endif

/**
 * @brief Initialize Library
 *
 */
void lib_filesystem_littlefs_init(void);

#endif
#endif
