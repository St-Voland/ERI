/*
 * Name: memory_manager.h
 * Description: header for main file in memory_manager module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 31 May, 2015
*/

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "core/header/common/types.h"
#include <stdlib.h>
#include <string.h>

void* vol_malloc( size_t size, e_ret_code& return_code );

void* vol_memcpy( void* to, const void* from,
                  u32 size_in_bytes, e_ret_code& return_code );

void vol_free( void* ptr, e_ret_code& return_code );

#endif // MEMORY_MANAGER_H
