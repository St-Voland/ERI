/*
 * Name: core.h
 * Description: core file
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 26 May, 2015
 * Review: 26 May, 2015
*/

#ifndef CORE_H
#define CORE_H

#include "core/header/log/log.h"

Log* log = &Log::get_instance();


#define LOGD( msg, ... ) log->debug( __FILE__, __LINE__, msg, __VA_ARGS__ )
#define LOGW( msg, ... ) log->warning( __FILE__, __LINE__, msg, __VA_ARGS__ )
#define LOGE( msg, ... ) log->error( __FILE__, __LINE__, msg, __VA_ARGS__ )

//#define LOGD( msg ) LOGD( msg, NULL )
//#define LOGW( msg ) LOGW( msg, NULL )

#endif // CORE_H
