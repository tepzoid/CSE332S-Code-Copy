//Header.h
// This file declares functions and enumerations used in Lab1.cpp
//Author: Jinfeng Chen   c.jinfeng@wustl.edu
#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

enum class arrIndex {prgm_path, input_name, total_cmd_line}; //enumeration for different array indices related to argv []
											

enum class suc_fail_code {success , file_cannot_open, incorrect_usage};//enumerate all error cases here.
								

int main(int argc, char * argv[]);
suc_fail_code parse(vector<string>&, const char*);
			//declares the function that parses the input file, whose name is a C-style string from the second paratmeter
int usageMsg(const char* program_name);
