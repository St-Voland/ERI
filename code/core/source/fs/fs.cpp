/*
 * Name: fs.c
 * Description: source of main file in file system module
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 26 May, 2015
 * Review: 26 May, 2015
*/

#include "core/header/fs/fs.h"

Vol_fs::Vol_fs( const char* file_name )
{
    m_file = NULL;
    open( file_name );
}

e_ret_code Vol_fs::write( const char* data_to_write, s32 size_in_bytes )
{
    fwrite( data_to_write, sizeof( char ),
            size_in_bytes, m_file );
    return vol_ok;
}

e_ret_code Vol_fs::write( const char* data_to_write )
{
//    m_file << data_to_write;
    fwrite( data_to_write, sizeof( char ),
            vol_strlen( data_to_write ), m_file );
    return vol_ok;
}

e_ret_code Vol_fs::read()
{
    return vol_ok;
}

e_ret_code Vol_fs::open( const char* file_name )
{
    close();
//    m_file.open( file_name, std::ios::out | std::ios::app );
    m_file = fopen( file_name, "at" );
//    fwrite(адрес записываемой величины, размер одного экземпляра, количество записываемых величин, имя логического файла);
    return vol_ok;
}

e_ret_code Vol_fs::close()
{
//    m_file.close();
    if ( NULL != m_file )
    {
        fclose( m_file );
    }
    return vol_ok;
}

Vol_fs::~Vol_fs(){}

