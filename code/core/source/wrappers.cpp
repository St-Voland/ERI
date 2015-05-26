/*
 * Name: wrappers.cpp
 * Description: source for dummy wrappers on standart functions
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 26 May, 2015
 * Review: 26 May, 2015
*/

#include "core/header/wrappers.h"

s32 vol_strlen( const char* str )
{
    return s32( strlen ( str ) );
}
