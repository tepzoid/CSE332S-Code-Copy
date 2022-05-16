//TicTacToeGame.cpp
//
//Author: Jinfeng Chen    c.jinfeng@wustl.edu
//

#include "TicTacToeGame.h"
#include "Lab3.h"

using namespace std;

//Set the dimension of the entire gameboard to 5 by 5 square, including non-gameplay area(edges)
	//Only defined one edge because the shape is a square
//tictactoeGame::const int boardDimen = 5;

//Create an empty vector to hold gamepieces
vector<string> board;


//Create a const int to hold the dimension of the square game board
const int boardDi = 5;








//Constructor for tictactoe class
//Initalize the board with 25 squares, where the squares at the middle are ready for user input
//Squares at the edges are blank and stay blank

tictactoeGame::tictactoeGame(): boardDimen(boardDi) {

	isPlayerX = true;

	for (int height = 0; height < boardDimen; ++height) {
		for (int width = 0; width < boardDimen; ++width) {

				
				board.push_back("");
	
		}
	}


};


//This method tells if the game should be ended (i.e. have a three-in-a-row for a player)

bool tictactoeGame::done() {
	
	//Treat the 3 by 3 tic-tac-toe game board as a 3 by 3 matrix, so the top left corner is the "a11" element
	//middle element is the "a22" element, the top right corner one is the "a13" element, etc.
	//the first number represents the row, the second number represents the column
	//
	//The index refers to the one in the class member variable--vector "board"

	//Declare bottom row index
	int a31Ind = 6;
	int a32Ind = 7;
	int a33Ind = 8;

	//Declare middle row index
	int a21Ind = 11;
	int a22Ind = 12;
	int a23Ind = 13;

	//Declare top row index
	int a11Ind = 16;
	int a12Ind = 17;
	int a13Ind = 18;


	if ( ! board[a31Ind].empty() ) {

		//Check if the bottom row has a three-in-a-row
		if ((board[a31Ind] == board[a32Ind]) && (board[a32Ind] == board[a33Ind])) {
			return true;
		 }

		//Check if the left column has a three-in-a-row
		if ((board[a31Ind] == board[a21Ind]) && (board[a21Ind] == board[a11Ind])) {
			return true;
		}

		//Check if the diagonal has a three-in-a-row
		if ((board[a31Ind] == board[a22Ind]) && (board[a22Ind] == board[a13Ind])) {
			return true;
		}

	}
	
	if ( ! board[a32Ind].empty()) {

		//Check if the middle column has a three-in-a-row
		if ((board[a32Ind] == board[a22Ind]) && (board[a22Ind] == board[a12Ind])) {
			return true;
		}
	}

	if ( ! board[a33Ind].empty()) {

		//Check if the right column has a three-in-a-row
		if ((board[a33Ind] == board[a23Ind]) && (board[a23Ind] == board[a13Ind])) {
			return true;
		}

		//Check if the diagonal has a three-in-a-row
		if ((board[a33Ind] == board[a22Ind]) && (board[a22Ind] == board[a11Ind])) {
			return true;
		}

	}

	if ( ! board[a21Ind].empty()) {

		//Check if the middle row has a three-in-a-row
		if ((board[a21Ind] == board[a22Ind]) && (board[a22Ind] == board[a23Ind])) {
			return true;
		}
	}

	if ( ! board[a11Ind].empty()) {

		//Check if the top row has a three-in-a-row
		if ((board[a11Ind] == board[a12Ind]) && (board[a12Ind] == board[a13Ind])) {
			return true;
		}
	}


	return false;

};

//This method tells if there is a draw in the game. It will return false if there are moves left in the game or 
//the done () method returns true; otherwise, this method returns true
bool tictactoeGame::draw() {

	//Vector that holds indices for innner 3 by 3 game board locations
	vector<int> indices = { 6, 7, 8, 11, 12, 13, 16, 17, 18 };

	//Return false--not draw--if there are still moves left
	for (int i : indices) {
		if (board[i].empty()) {
			return false;
		}
	}

	if ( done() ) {
		return false;
	}

	return true;
}

//This method prompts the user to input instructions, either as the coordinates for the next move, or the "quit" instruction
int tictactoeGame::prompt(unsigned int& horCoord, unsigned int& verCoord) {

	//Create the string that holds user input
	string rawInput;

	//Create the boolean that tracks whether the program should keep prompting the user for correct input
	bool needInput = true;

	//Keep prompting user for input if the input is invalid
	//Try to extract two coordinates
	while ( needInput ){
		cout << "Please give a pair of comma-separated coordinates between 0,0 and 3,3 " << endl;
		cout << "If you would like to quit the game, please type \"quit\"" << endl;

		cin >> rawInput;


		//Check if the user input is "quit"
		//If so, the program returns the designated return code

		if (rawInput.compare("quit") == 0) {
			return static_cast<int>(suc_fail_code::quit_requested);
		}
		
		//Find comma character in input string (rawInput) and replace it with a space
		//If the comma not found, the program prints an error message and keeps prompting the user for input
		else if (rawInput.find(",") == -1) {

			cout << "Invalid input" << endl;
		}
		//If the comma is found, then the program attempts to extract two unsigned integers
		else {

			//Replace the comma in the input string with a space to facilitate istringstream extraction

			unsigned int commaPos = 1;// Position of the comma in the string
			unsigned int replaceLength = 1;//Length of the string to be replaced
			rawInput.replace(commaPos, replaceLength, " ");

			

			istringstream iss(rawInput);



			//Check if extractions are successful
			if ( (iss >> horCoord) && (iss >> verCoord ) ) {

				unsigned int lowLim = 1; //Lower limit of a valid coordinate
				unsigned int highLim = 3;//Upper limit of a valid coordinate

				//If extractions are successful, then the program checks if coordinates are valid for game play

				//Checks if the horizatonal coordinate is between 1 and 3
				if ((horCoord >= lowLim) && (horCoord <= highLim)) {

					//Checks if the vertical coordinate is between 1 and 3
					if ((verCoord >= lowLim) && (verCoord <= highLim)) {

						needInput = false; //Stop promting the user from more input

				
						
					}
					else {



						cout << "Invalid coordinates" << endl;
					}
				}
				else {


					cout << "Invalid coordinates" << endl;
				}


			}
			//If any extraction is not successful, 
			//the program prints an error message and keeps prompting user for input
			else {
				cout << "Invalid coordinates" << endl;
			}
			

		}
		



	}

	return static_cast<int>(suc_fail_code::success);
}

//This method checks if the square at the input coordinates is empty
//Prints updated gameboard and all valid moves the current player has made once a valid move is made
int tictactoeGame::turn() {
	

	//Declare variables to hold user input coordinates
	unsigned int horiCoor;
	unsigned int vertCoor;

	//Create a boolean to record if the player has entered a valid move
	bool validMv = false;

	//Create an int to hold the return value of the prompt() method call
	int returnCode;

	//A loop that keeps prompting the player for a valid move (or "quit")
	while (!validMv) {

		if (isPlayerX) {
			cout << "\nPlayer X's turn: \n" << endl;
		}
		else {
			cout << "\nPlayer O's turn: \n" << endl;
		}

		//Prompt the player to enter a coordinate pair
		returnCode = prompt(horiCoor, vertCoor);

		//Checks if the player enters "quit"
		if (returnCode == static_cast<int>(suc_fail_code::quit_requested)) {
			return returnCode;
		}
		else {
			
			//Get the (board vector) index corresponding to the coordinates
			unsigned int index = vertCoor * boardDimen + horiCoor;

			//Check if the square is empty
			if (board[index].empty()) {

				//Breaks the loop
				validMv = true;

				//Create string that stores the most recent valid move
				string validMove = to_string(horiCoor) + "," + to_string(vertCoor);



				//Moves the piece to the empty square depends on which player is playing
				if (isPlayerX) {
					board[index] = "X";

					
					//Record the valid move to the class variable
					playerXMoves += ( validMove + "; ");
					
					
					
				}
				else {
					board[index] = "O";

					

					//Record the valid move to the class variable
					playerOMoves += (validMove + "; "  );
					
					
				}

				//Print out the updated gameboard with a blank line at the bottom
				cout << "\n" << *this << "\n" << endl;
				
				
				//Print valid moves that has been made
				if (isPlayerX) {
					cout << "Player X: " << playerXMoves << endl;
				}
				else {
					cout << "Player O: " << playerOMoves << endl;
				}

			}
			else {
				cout << "\n There is already a game piece at that location \n" << endl;
			}



		}

	}

		

	//Alternate the player
	isPlayerX = !isPlayerX;

	return static_cast<int>(suc_fail_code::success);
}


int tictactoeGame::play() {

	//Create a variable to keep track of how many turns are being played
	unsigned int turnCount = 0;

	//Prints the game board
	cout << *this << "\n" << endl;

	

	//Create a boolean to as a while loop condition
	bool keepGoing = true;

	//A loop that keep having turns in tic-tac-toe game
	while (keepGoing) {



		//If the player requests to quit the game, the code prints out how many turns are played 
		//and a message saying the player quits the game
		if (turn() == static_cast<int>(suc_fail_code::quit_requested)) {

			cout << to_string(turnCount) << " turns are played. You have requested to quit the game." << endl;

			keepGoing = false;//break the loop, probably don't need this line of code

			return static_cast<int>(suc_fail_code::quit_requested);
		}

		//If done() returns true, the code prints out who won the game
		if (done()) {

			string name;

			//Create corresponding player name
			if (isPlayerX) {
				name = "Player O ";//Because after each turn() call, isPlayerX becomes the opposite one, ready for the next turn
				//This is even true when there are no more turn (someone wins the game), so that's why isPlayerX prints "Player O"
			}
			else {
				name = "Player X ";//See comment above
			}

			//Prints who won the game
			cout << "\n" << name << "won. Congratulations!" << endl;


			keepGoing = false;//break the loop, probably don't need this line of code

			return static_cast<int>(suc_fail_code::success);
		}

		++turnCount;

		if (draw()) {
			cout << to_string(turnCount) << " turns are played. The game is a draw." << endl;

			keepGoing = false;//break the loop, probably don't need this line of code

			return static_cast<int>(suc_fail_code::game_draw);
		}


		


	}
	
	//This one catches unexpected errors--this line of code should never run
	return static_cast<int>(suc_fail_code::success);

	
}


//Define the insertion operator << so other programs can print tictactoeGame objects
ostream& operator<<(ostream & o, const tictactoeGame & game) {
	int dimen = game.getDimen();
	
	

	for (int height = dimen - 1; height >= 0 ; -- height) {

		//Print row number
		o << height << " ";

		for (int width = 0; width < dimen ; ++ width) {

			int index = dimen * height + width;
			
			//If the space is empty, two spaces are printed to hold place
			if (game.board[index].empty()) {
				o << "  ";
			}
			//If the space(string) is not empty, the string content is printed
			else {
				o << game.board[index] << " ";
			}
		}

		//Flush the line, so a new line will be printed next time
		o << endl;
	}

	//Print labeled horizontal axis coordinates
	o << "  0 1 2 3 4 ";

	return o;

};


	


