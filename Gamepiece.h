//Gamepiece.h
// 
//Header file for Gamepiece.cpp, including declarations for gamepiece object
//
//Author: Jinfeng Chen   c.jinfeng@wustl.edu



#pragma once
#include<string>
#include<vector>


struct gamepiece {
	gamepiece(std::string DispInfo);

	std::string display_info;

	int setDispInfo(std::string newInfo);
};


