//Gameboard.h
//This header file declares functions and pre-comnpiler instructions for Gameboard.cpp
//Author: Jinfeng Chen    c.jinfeng@wustl.edu



#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <vector>

#include "Gamepiece.h"
#include "Header.h"



int read_dim(std::ifstream& ifs, unsigned int& width, unsigned int& height);

int read_piece(std::ifstream& ifs, std::vector<game_piece>& gamepieces, unsigned int & width, unsigned int & height);

int printPieces(const std::vector<game_piece>& pieces, unsigned int & width, unsigned int & height);

