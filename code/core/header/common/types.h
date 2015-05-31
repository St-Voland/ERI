/*
 * Name: types.h
 * Description: types redefining
 * Author: G.Molyboga(St.George.Molyboga@gmail.com)
 * Date: 24 May, 2015
 * Review: 31 May, 2015
*/

#ifndef TYPES_H
#define TYPES_H

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef signed char s8;

enum e_ret_code
{
    vol_ok                     = 0,
    vol_general_failure        = -1,
    vol_memory_allocation_failure         = -2,
    vol_authentication_failure = -3,
    vol_exceeded_buffer_failure = -4,
    vol_memory_copy_failure         = -5
};

enum e_log_settings
{
    vol_disable_log              = 0,
    vol_write_to_file            = 1,
    vol_write_to_stdout          = 2,
    vol_write_both               = vol_write_to_file | vol_write_to_stdout
};

enum e_log_message_level
{
    vol_log_level_all           = 0,
    vol_log_level_message       = 1,
    vol_log_level_info          = 2,
    vol_log_level_debug         = 3,
    vol_log_level_warning       = 4,
    vol_log_level_assert        = 5,
    vol_log_level_error         = 6,
    vol_log_level_magic         = 7,
    vol_log_level_none          = 8
};

#endif // TYPES_H
