/*
 * Name: app.cpp
 * Description: entry point
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 30 May, 2015
 * Review: 30 May, 2015
*/

#include <stdio.h>
#include "core/header/core.h"
#include "core/header/memory/memory_manager.h"
//#include "core/header/log/log.h"

int main()
{
    LOGI( "The program starts!", NULL );
    e_ret_code ret_code;
    int* l = (int*)vol_malloc( 5, ret_code );
    LOGE( "ptr = %p", l );
    vol_free( l, ret_code );
    return 0;
}

