/*
 * Name: memory_manager.h
 * Description: header for main file in memory_manager module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 26 May, 2015
*/

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "core/header/types.h"
#include <stdlib.h>
#include <string.h>

const u32 c_stack_buffer_size = 10000;
u8 stack_buffer[ c_stack_buffer_size + 1 ];

void* vol_malloc( size_t size, e_ret_code& return_code );

void* vol_memcpy( void* to, const void* from,
                  u32 size_in_bytes, e_ret_code& return_code );

#endif // MEMORY_MANAGER_H
