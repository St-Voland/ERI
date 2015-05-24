/*
 * Name: log.cpp
 * Description: main file in log module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 24 May, 2015
*/

#include "core/header/log/log.h"
#include <iostream>

const u32 c_log_max_message_length = 512;

Log::Log():
    m_max_message_length( c_log_max_message_length )
{
    printf( "Log::Log() was called\n" );
    u8 return_code = -1;
    m_buffer = ( u8* )vol_malloc( m_max_message_length + 1, return_code );
}

void Log::common( const char* format, ... )
{
    va_list varArgs;
    va_start( varArgs, format );

    s32 current_message_length = vsnprintf(
                ( char* )m_buffer, m_max_message_length, format, varArgs);
    if ( current_message_length > m_max_message_length )
    {
        //TODO: handle this type of mistake
        va_end( varArgs );
        return;
    }
    m_buffer[ current_message_length ] = 0;
    std::cout << m_buffer << std::endl;
    va_end( varArgs );
}
