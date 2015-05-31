/*
 * Name: log.cpp
 * Description: main file in log module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 30 May, 2015
*/

#include "core/header/log/log.h"

namespace LogManager
{

const char c_default_log_file_name[] = "log.txt";

Log::Log():
    m_max_message_length( c_log_max_message_length ),
    m_log_settings( c_default_log_settings ),
    m_max_message_level( c_log_message_level )
{
    e_ret_code ret_code;
    vol_memcpy( m_file_name, c_default_log_file_name,
                sizeof( c_default_log_file_name ), ret_code );
    m_buffer = ( u8* )vol_malloc( m_max_message_length + 1, ret_code );
    if ( vol_ok != ret_code )
    {
        //TODO: error handler
    }
}

Log::~Log()
{
//    m_buffer = ( u8* )vol_malloc( m_max_message_length + 1, return_code );
    e_ret_code ret_code;
    vol_free( m_buffer, ret_code );
    if ( vol_ok != ret_code )
    {
        //TODO: error handler
    }
}

e_ret_code Log::write( e_log_message_level level, const char* file_name,
                  s32 line, const char* format, ... )
{
    e_ret_code return_code = vol_general_failure;
    if ( level < m_max_message_level )
    {
        //TODO: error handler
        return vol_ok;
    }

    switch ( level )
    {
    case vol_log_level_message:
        return_code = common( false,  COLOUR_RESET "[MESSAGE]" COLOUR_RESET ": [%s(%d)]: ", file_name, line );
        break;
    case vol_log_level_info:
        return_code = common( false,  COLOUR_RESET "[INFO===]" COLOUR_RESET ": [%s(%d)]: ", file_name, line );
        break;
    case vol_log_level_debug:
        return_code = common( false,  COLOUR_CYAN "[DEBUG==]" COLOUR_RESET ": [%s(%d)]: ", file_name, line );
        break;
    case vol_log_level_warning:
        return_code = common( false,  COLOUR_YELLOW "[WARNING]" COLOUR_RESET ": [%s(%d)]: ", file_name, line );
        break;
    case vol_log_level_error:
        return_code = common( false,  COLOUR_RED "[ERROR==]" COLOUR_RESET ": [%s(%d)]: ", file_name, line );
        break;
    default:
        break;
    }

    if ( vol_ok != return_code )
    {
        //TODO: error handler
    }

    va_list varArgs;
    va_start( varArgs, format );
    return_code = common( true, format, varArgs );
    va_end( varArgs );
    if ( vol_ok != return_code )
    {
        //TODO: error handler
    }
    return return_code;
}

e_ret_code Log::common( bool new_line, const char* format,
                        const va_list& varArgs )
{
    if ( vol_disable_log != m_log_settings )
    {
        s32 current_message_length = vsnprintf(
                    ( char* )m_buffer, m_max_message_length, format, varArgs);
        if ( current_message_length + 1 > m_max_message_length )
        {
            //TODO: handle this type of mistake
            return vol_exceeded_buffer_failure;
        }

        if ( new_line )
        {
            m_buffer[ current_message_length ] = '\n';
            m_buffer[ current_message_length + 1 ] = 0;
        }
        else
        {
            m_buffer[ current_message_length ] = 0;
        }

        if ( vol_write_to_stdout & m_log_settings )
        {
            std::cout << m_buffer;
        }

        if ( vol_write_to_file & m_log_settings )
        {
            Vol_fs log_file( m_file_name );
            log_file.write( ( const char* )m_buffer );
            log_file.close();
        }
    }
    return vol_ok;
}

e_ret_code Log::common( bool new_line, const char* format, ... )
{
    e_ret_code return_code = vol_ok;
    if ( vol_disable_log != m_log_settings )
    {
        va_list varArgs;
        va_start( varArgs, format );
        return_code = common( new_line, format, varArgs );
        va_end( varArgs );
    }
    return return_code;
}

} //namespace LogManager
