/*
 * Name: log.h
 * Description: header for main file in log module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 31 May, 2015
*/

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <stdarg.h>
#include "core/header/common/types.h"
#include "core/header/memory/memory_manager.h"
#include "core/header/fs/fs.h"


namespace LogManager
{

class Log
{
public:
    static Log& instance()
    {
        static Log m_instance;
        return m_instance;
    }

    e_ret_code common( bool new_line, const char* format, ... );
    e_ret_code common( bool new_line, const char* format,
                       const va_list& varArgs );
    e_ret_code write( e_log_message_level level, const char* file_name,
                      s32 line, const char* format, ... );

private:
    Log();//deprecated constructor
    ~Log();//deprecated destructor
    const Log& operator=( const Log& other );
    Log( const Log& other );
private:
    //default values:
    static const s32 c_log_max_message_length = 512;
    static const e_log_settings c_default_log_settings = vol_write_both;
    static const s32 c_log_max_file_name = 512;
    static const e_log_message_level c_log_message_level = vol_log_level_all;

private:
    const s32 m_max_message_length;
    e_log_settings m_log_settings;
    e_log_message_level m_max_message_level;

    u8* m_buffer;
//    u8 m_buffer[ c_log_max_message_length + 1 ];
    char m_file_name[ c_log_max_file_name + 1 ];
};

}//namespace LogManager

#ifdef USE_LOG
#define LOGM( msg, ... ) LogManager::Log::instance().write( vol_log_level_message, __FILE__, __LINE__, msg, __VA_ARGS__ )
#define LOGI( msg, ... ) LogManager::Log::instance().write( vol_log_level_info, __FILE__, __LINE__, msg, __VA_ARGS__ )
#define LOGD( msg, ... ) LogManager::Log::instance().write( vol_log_level_debug, __FILE__, __LINE__, msg, __VA_ARGS__ )
#define LOGW( msg, ... ) LogManager::Log::instance().write( vol_log_level_warning, __FILE__, __LINE__, msg, __VA_ARGS__ )
#define LOGE( msg, ... ) LogManager::Log::instance().write( vol_log_level_error, __FILE__, __LINE__, msg, __VA_ARGS__ )
#else
#define LOGM( msg, ... ) (void(0))
#define LOGI( msg, ... ) (void(0))
#define LOGD( msg, ... ) (void(0))
#define LOGW( msg, ... ) (void(0))
#define LOGE( msg, ... ) (void(0))
#endif

#endif // LOG_H
