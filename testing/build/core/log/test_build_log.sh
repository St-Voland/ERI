function test.log
{
current_time_stamp=$(get_app_timestamp)

}


function get_app_timestamp
{
stat -c %Y $app_path/$target
}

timestamp=$(get_app_timestamp)
echo $timestamp

testing_folder=$(pwd)
testing_build_folder=$testing_folder/build
testing_build_core_folder=$testing_build_folder/core
testing_build_log_folder=$testing_build_core_folder/log
testing_build_fs_folder=$testing_build_core_folder/fs
testing_build_memory_folder=$testing_build_core_folder/memory
testing_build_wrappers_folder=$testing_build_core_folder/wrappers

target=application
app_path=$(testing_folder)/../bin
build_path=$(testing_folder)/../build

code_folder=$testing_folder/../code
code_core_folder=$code_folder/core

