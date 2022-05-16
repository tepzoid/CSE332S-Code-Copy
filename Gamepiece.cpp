//Gamepiece.cpp
//
//Souce file for gamepiece object, defining gamepiece constructor
//
//Author: Jinfeng Chen   c.jinfeng@wustl.edu
//

#include "Gamepiece.h"
#include "Lab3.h"

using namespace std;

//Define the gamepiece contructor
gamepiece::gamepiece(string DispInfo) : display_info(DispInfo) {};

gamepiece::int setDispInfo(std::string newInfo) {

	gamepiece::display_info = newInfo;

	return static_cast<int>(suc_fail_code::success);
}