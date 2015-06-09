
Colour_default="\033[0m"
Colour_lighter="\033[1m"
Colour_darker="\033[2m"
Colour_underline="\033[4m"
Colour_blink="\033[5m"
Colour_reverse="\033[7m"

Colour_cancel_half_intensity="\033[22m"
Colour_cancel_underline="\033[24m"
Colour_cancel_blink="\033[25m"
Colour_cancel_reverse="\033[27m"

Colour_text_black="\033[30m"
Colour_text_red="\033[31m"
Colour_text_green="\033[32m"
Colour_text_yellow="\033[33m"
Colour_text_blue="\033[34m"
Colour_text_purple="\033[35m"
Colour_text_cyan="\033[36m"
Colour_text_gray="\033[37m"

Colour_background_black="\033[40m"
Colour_background_red="\033[41m"
Colour_background_green="\033[42m"
Colour_background_yellow="\033[43m"
Colour_background_blue="\033[44m"
Colour_background_purple="\033[45m"
Colour_background_cyan="\033[46m"
Colour_background_gray="\033[47m"

function print_lighter_green_msg
{
	echo -en "$Colour_text_green$Colour_lighter$1$Colour_default\n"
}

function print_darker_green_msg
{
	echo -en "$Colour_text_green$Colour_darker$1$Colour_default\n"
}

function print_green_msg
{
	echo -en "$Colour_text_green$1$Colour_default\n"
}

function print_lighter_red_msg
{
	echo -en "$Colour_text_red$Colour_lighter$1$Colour_default\n"
}

function print_darker_red_msg
{
	echo -en "$Colour_text_red$Colour_darker$1$Colour_default\n"
}

function print_red_msg
{
	echo -en "$Colour_text_red$1$Colour_default\n"
}

print_lighter_green_msg "lighter_green_msg"
print_darker_green_msg "darker_green_msg"
print_green_msg "green_msg"

print_lighter_red_msg "lighter_red_msg"
print_darker_red_msg "darker_red_msg"
print_red_msg "red_msg"


export testing_folder=$(pwd)
export testing_build_folder=$testing_folder/build
export testing_build_core_folder=$testing_build_folder/core
export testing_build_log_folder=$testing_build_core_folder/log
export testing_build_fs_folder=$testing_build_core_folder/fs
export testing_build_memory_folder=$testing_build_core_folder/memory
export testing_build_wrappers_folder=$testing_build_core_folder/wrappers

export target=application
export app_path=$testing_folder/../bin
export build_path=$testing_folder/../build

export code_folder=$testing_folder/../code
export code_core_folder=$code_folder/core
export dependency_folder=$testing_folder/dependency_map

function get_app_timestamp
{
stat -c %Y $app_path/$target
}

function get_obj_timestamp
{
stat -c %Y $build_path/$1
}

timestamp=$(get_app_timestamp)
echo $timestamp









