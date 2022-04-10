//Gamepiece.h
// This file declares functions and enumerations used in Gamepiece.cpp
//Author: Jinfeng Chen   c.jinfeng@wustl.edu
//Gamepiece.h
//This header file declare enum, struct, and funtions used in Gamepiece.cpp
//Author: Jinfeng Chen   c.jinfeng@wustl.edu

#pragma once

#include<vector>
#include<string>

#include "Header.h"



enum class piece_color { no_color, red, black, white, invalid_color = -1};//enumeration for gamepiece colors

//create a struct to represent a game piece
struct game_piece {
	game_piece(piece_color pcolor, std::string pDispInfo, std::string pName);

	piece_color color;
	std::string name;
	std::string display_info;
};


std::string getColor(piece_color color);

piece_color getEnumColor(std::string color);







