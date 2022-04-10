// Gamepiece.cpp 
// 
// This file contains the game_piece constructor, getColor() and getEnumColor()
// 
// Author: Jinfeng Chen   c.jinfeng@wustl.edu
//

#include "Gamepiece.h"



using namespace std;

//Define game_piece constructor
game_piece::game_piece(piece_color pcolor, std::string pDispInfo, std::string pName): color(pcolor), display_info(pDispInfo), name(pName) {}

//returns C++ string representing the color of the gamepiece; the string is composed of all lowercase letters
string getColor(piece_color color) {
	string output;

	if (color == piece_color::black) {
		output = "black";
	}
	else if(color == piece_color::red) {
		output = "red";
	}
	else if (color == piece_color::white) {
		output = "white";
	}
	else if(color == piece_color::no_color){
		output = "no color";
	}
	else {
		output = "invalid color";
	}

	return output;
}

//returns piece_color enum corresponding to the input string
piece_color getEnumColor(string color) {
	string lowercase = toLowercase(color);
	

	if (lowercase == "red") {
		return piece_color::red;
	}
	else if(lowercase == "black") {
		return piece_color::black;
	}
	else if (lowercase == "white") {
		return piece_color::white;
	}
	else if (lowercase == " ") {
		return piece_color::no_color;
	}
	else {
		return piece_color::invalid_color;
	}

}
