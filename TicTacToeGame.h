//TicTacToeGame.h
//Header file for TicTacToeGame.cpp
//
//Author: Jinfeng Chen   c.jinfeng@wustl.edu
//


#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


class tictactoeGame {
	friend std::ostream &operator<<(std::ostream &o, const tictactoeGame &game);

private:
	const int boardDimen;

	std::vector<std::string> board;

	std::string playerXMoves;

	std::string playerOMoves;

	bool isPlayerX;//keep track who is playing this turn

public:

	tictactoeGame();

	int getDimen() const { return boardDimen; };

	bool done();

	bool draw();

	int prompt(unsigned int& coord1, unsigned int& coord2);

	int turn();

	int play();

	
};



std::ostream& operator<<(std::ostream& o, const tictactoeGame& game);
