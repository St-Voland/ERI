/*
 * Name: wrappers.h
 * Description: header for dummy wrappers on standart functions
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 26 May, 2015
 * Review: 31 May, 2015
*/

#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "core/header/common/types.h"
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define COLOUR_RED ANSI_COLOR_RED
#define COLOUR_GREEN ANSI_COLOR_GREEN
#define COLOUR_YELLOW ANSI_COLOR_YELLOW
#define COLOUR_BLUE ANSI_COLOR_BLUE
#define COLOUR_MAGENTA ANSI_COLOR_MAGENTA
#define COLOUR_CYAN ANSI_COLOR_CYAN
#define COLOUR_RESET ANSI_COLOR_RESET

s32 vol_strlen( const char* str );

#endif // WRAPPERS_H
