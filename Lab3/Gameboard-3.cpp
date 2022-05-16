//Gameboard-3.cpp
//
//This file includes variables and methods for printing gameboard
//
//Author: Jinfeng Chen   c.jinfeng@wustl.edu

#include "Gameboard-3.h"
#include "Lab3.h"

using namespace std;

int printPieces(const vector<gamepiece>& pieces, unsigned int& width, unsigned int& height) {

	//print all game pieces
	//return error code if the size of the vector does not match gameboard dimension

		for (int y = height - 1; y >= 0; --y) {


			for (unsigned int x = 0; x < width; ++x) {
				int index = width * y + x;
				cout << pieces[index].display_info << " ";
			}
			cout << endl;
		}

		return static_cast<int>(suc_fail_code::success);


}
