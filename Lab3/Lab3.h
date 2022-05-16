//Lab3.h 
// Header file for Lab3.cpp
//
//Author: Jinfeng Chen   c.jinfeng@wustl.edu
//
#pragma once

#include<vector>
#include<algorithm>
#include<iostream>



enum class arrIndex { prgm_path, input_name, total_cmd_line }; //enumeration for different array indices related to argv []

enum class suc_fail_code {
	success, incorrect_usage, quit_requested, game_draw
};
//enumerate all error cases here.

int main(int argc, char* argv[]);



int usageMsg(const char* program_name, const char* more_info);
