//Gameboard.cpp
//
//This file contains functions that read in gameboard dimensions, read game pieces, and 
//print games pieces
//
//Author: Jinfeng Chen	 c.jinfeng@wustl.edu




#include "Gameboard.h"



using namespace std;

//Reads in the width and height of the gameboard
int read_dim(ifstream& ifs, unsigned int & width, unsigned int & height) {
	string temp;

	
	if (ifs.is_open()) {

		//Try to extract the first line from the file
		
		if (getline(ifs, temp)) {

			//wrap the first line from the file in a string stream
			istringstream iss(temp);

			//extract two numbers from the line
			//if either extraction failed, cannot_extract_dimen error is returned
			if (iss >> width && iss >> height) {
				
				return static_cast<int>(suc_fail_code::success);
			}
			else {
				return static_cast<int>(suc_fail_code::cannot_extract_dimen);
			}

		}
		else {
			return static_cast<int>(suc_fail_code::cannot_read_line);
		}
		
	}
	else {
		return static_cast<int>(suc_fail_code::file_cannot_open);
	}

}

int read_piece(ifstream& ifs, vector<game_piece>& gamepieces, unsigned int & width, unsigned int & height) {
	string temp; //a string that stores a line extracted from input file stream
	bool success = false;// checks if any line extraction is successful

	string color;
	string name;
	string toDisplay;
	unsigned int xPos = 0;//an unsigned interger that holds horizontal position
	unsigned int yPos = 0;//an unsigned interger that holds vertical position
	
	while (getline(ifs, temp)) {

		istringstream iss(temp);

		//extract five strings/numbers from the line; if any extraction fail, the line gets skipped
		if (iss >> color && iss >> name && iss >> toDisplay && iss >> xPos && iss >> yPos){


			//compare the x and y position of the piece with the board dimension
			//if x or y exceeds the board dimension, the line is skipped
			if ((xPos < width) && (yPos < height)) {										
				

				//Checks if the piece color is invalid
				if (getEnumColor(color) != piece_color::invalid_color) {
					
					 int index = width * yPos + xPos;//calculate vector index

					//Set the gamepiece at that index with the extracted info
					gamepieces[index].color = getEnumColor(color);
					gamepieces[index].name = name;
					gamepieces[index].display_info = toDisplay;

					success = true;//becomes true if at least one well-formed piece is found
				}
			}
		}
	}

	if (success) {
		return static_cast<int>(suc_fail_code::success);
	}
	else {
		return static_cast<int>(suc_fail_code::cannot_find_well_formed_piece);
	}


}


int printPieces(const vector<game_piece>& pieces, unsigned int & width, unsigned int & height) {

	//print all game pieces
	//return error code if the size of the vector does not match gameboard dimension
	if(pieces.size() == static_cast<unsigned long long>(width)  
		* static_cast<unsigned long long>(height) ){

		

		for ( int y = height - 1; y >= 0; --y) {
			

			for (unsigned int x = 0; x < width ; ++x) {
				int index = width  * y + x;
				cout << pieces[index].display_info << " ";
			}
			cout << endl;
		}

		return static_cast<int>(suc_fail_code::success);
	}
	else {
		return static_cast<int>(suc_fail_code::vector_not_match_dimen);
	}
	
}

