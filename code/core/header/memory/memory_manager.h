/*
 * Name: memory_manager.h
 * Description: header for main file in memory_manager module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 24 May, 2015
*/

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "core/header/types.h"
#include <stdlib.h>

const u8 c_stack_buffer_size = 10000;
u8 stack_buffer[ c_stack_buffer_size + 1 ];

void* vol_malloc( size_t size, u8& return_code )
{
    //TODO: normal return codes
    void* return_value = malloc( size );
    if ( NULL == return_value )
    {
        return_code = -7;
        return_value = stack_buffer;
    }
    return_code = 0;
    return return_value;
}

#endif // MEMORY_MANAGER_H
