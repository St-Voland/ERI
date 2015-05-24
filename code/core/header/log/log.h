/*
 * Name: log.h
 * Description: header for main file in log module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 24 May, 2015
*/

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include "core/header/types.h"
#include "core/header/memory/memory_manager.h"

class Log
{
public:
    static Log& get_instance()
    {
        static Log m_instance;
        return m_instance;
    }

    void common( const char* format, ... );
private:
    Log();//deprecated constructor

private:
    const u32 m_max_message_length;
    u8* m_buffer;
//    static Log* m_instance = NULL;
};


#endif // LOG_H
