/*
 * Name: fs.h
 * Description: header for main file in file system module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 26 May, 2015
 * Review: 26 May, 2015
*/

#ifndef FS_H
#define FS_H

#include "core/header/types.h"
//#include <fstream>
//#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "core/header/wrappers.h"

class Vol_fs
{
public:
    e_ret_code write( const char* data_to_write );
    e_ret_code write( const char* data_to_write,
                      s32 size_in_bytes );
    e_ret_code read();
    e_ret_code open( const char* file_name );
    e_ret_code close();

    Vol_fs( const char* file_name );
    ~Vol_fs();
private:
    FILE* m_file;
};


#endif // FS_H
