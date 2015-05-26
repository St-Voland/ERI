/*
 * Name: log.h
 * Description: header for main file in log module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 26 May, 2015
*/

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <stdarg.h>
#include "core/header/types.h"
#include "core/header/memory/memory_manager.h"
#include "core/header/fs/fs.h"

class Log
{
public:
    static Log& get_instance()
    {
        static Log m_instance;
        return m_instance;
    }

    e_ret_code common( bool new_line, const char* format, ... );
    e_ret_code common( bool new_line, const char* format,
                       const va_list& varArgs );
    e_ret_code debug( const char* file_name, s32 line,
                      const char* format, ... );
    e_ret_code warning( const char* file_name, s32 line,
                        const char* format, ... );
    e_ret_code error( const char* file_name, s32 line,
                      const char* format, ... );
private:
    Log();//deprecated constructor

private:
    //default values:
    static const s32 c_log_max_message_length = 512;
    static const e_log_settings c_default_log_settings = vol_write_to_stdout; //vol_write_both;
    static const s32 c_log_max_file_name = 512;
    static const e_log_message_level c_log_message_level = vol_log_level_all;

private:
    const s32 m_max_message_length;
    e_log_settings m_log_settings;
    e_log_message_level m_max_message_level;

//    u8* m_buffer;
    u8 m_buffer[ c_log_max_message_length + 1 ];
    char m_file_name[ c_log_max_file_name + 1 ];
};

#endif // LOG_H
