//Header.h
//This file declares functions and enumerations used in Lab2.cpp
//Author: Jinfeng Chen   c.jinfeng@wustl.edu

#pragma once

#include<vector>
#include<iostream>
#include <iomanip>


using namespace std;

enum class arrIndex { prgm_path, input_name, total_cmd_line }; //enumeration for different array indices related to argv []

enum class suc_fail_code {
	success, file_cannot_open, incorrect_usage, cannot_extract_dimen, cannot_read_line,
	cannot_find_well_formed_piece, vector_not_match_dimen, dimen_never_found};
	//enumerate all error cases here.

int main(int argc, char * argv[]);

string toLowercase(string & input);

int usageMsg(const char* program_name, const char * more_info); 


