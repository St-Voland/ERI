/*
 * Name: memory_manager.cpp
 * Description: source for main file in memory_manager module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 26 May, 2015
 * Review: 26 May, 2015
*/

#include "core/header/memory/memory_manager.h"

const u32 c_stack_buffer_size = 10000;
u8 stack_buffer[ c_stack_buffer_size + 1 ];

void* vol_malloc( size_t size, e_ret_code& return_code )
{
    //TODO: normal return codes
    void* return_value = malloc( size );
    if ( NULL == return_value )
    {
        return_code = vol_memory_allocation_failure;
//        return_value = stack_buffer;
    }
    return_code = vol_ok;
    return return_value;
}

void* vol_memcpy( void* to, const void* from,
                  u32 size_in_bytes, e_ret_code& return_code )
{
    void* return_value = memcpy( to, from, size_in_bytes );
    return_code = vol_memory_copy_failure;
    if ( NULL != return_value )
    {
        return_code = vol_ok;
    }
    return return_value;
}
