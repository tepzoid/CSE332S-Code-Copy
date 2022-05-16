
Author: Jinfeng Chen    c.jinfeng@wustl.edu

CSE 332S Lab 3

This program :
1. Takes "TicTacToe" as the sole command line
2. Prompts users to input instructions (coordinates/"quit")
3. Plays tic-tac-toe with the user.


Possible Return Values:
0 - game completed successfully; one player wins the game
1 - incorrect usage
2 - user requests to quit the game
3 - game ends in a draw



Errors and Warnings:


	E0366	"tictactoeGame::tictactoeGame()" provides no initializer for:	TicTacToeGame.cpp	
		Solved by adding an initialzer list definition in constructor definition

	E0040	expected an identifier	Lab3	H:\VisualSource\Lab3\Lab3\Lab3\TicTacToeGame.cpp	12	
		Solved by the same action above

	E1086	the object has type qualifiers that are not compatible with the member function 
		"tictactoeGame::getDimen"	H:\VisualSource\Lab3\Lab3\Lab3\TicTacToeGame.cpp	64	

		--Created by calling a non-const function on a const object. Solved by declaring the funtion
			constant by adding keyword "const" after the parentheses in the defintion/declaration


	E0330	"tictactoeGame::tictactoeGame()" (declared at line 17 of "H:\VISUALSOURCE\LAB3\LAB3\LAB3\TicTacToeGame.h")
		is inaccessible	Lab3	H:\VisualSource\Lab3\Lab3\Lab3\Lab3.cpp	14	

		--Created by declaring the constructor in default in a class, which made it private, not accessible
			by other classes. Solved by declaring the constructor public.

	C2433	'ostream': 'friend' not permitted on data declarations	
		Solved by adding std:: to ostream


	C2143	syntax error: missing ';' before '<'	
		Caused by missing std:: scoping, solved by changing the code to <std::string>

	E0040	expected an identifier	
		Solved by deleting tictactoeGame:: scoping operator
			How to define a class member function in source file?
				--Use return-type className::funcName() {}

				E.g. bool tictactoeGame::done() {...} instead of bool done() {...}

	E0070	incomplete type is not allowed
		Solved by adding #include<sstream> library
		Casued by incorrectly considering stringstream objects are included in the <iostream> library

	Run-time Error: Vector Subcript out-of-range
		Solved by using the correct syntax of replace()
		Cauased by using the incorrect overloaded version of replace()



Test Cases:

	1. Command argument: Lab3.exe TicTacToe

		Input: 1,1
		The program handles this input as expected, prints out the game board with an "X" at position 1,1

		Input: 1,4
		The program handles this input as expected, prints "Invalid coordinates" and prompts the user for another input

		Input: ser
		The program handles this input as expected, prints "Invalid input" and prompts the user for another input

		Input: 1,1
		The program handles this input as expected, prints ""There is already a game piece at that location" 
			and prompts the user for another input

		Input: quit
		The program quits as expected with return code 2

	2. Command argument: Lab3.exe TicTacToe

		Input: 1,1; 2,1; 1,2; 2,2; 1,3

		The program identifies the success completion of the game with return code 0

		Output of last turn:
		4
		3   X
		2   X O
		1   X O
		0
		  0 1 2 3 4

		Player X: 1,1; 1,2; 1,3;

		Player X won. Congratulations!

	3. Command argument: Lab3.exe TicTacToe

		Input: (alternating)
			Player X: 1,1; 3,1; 3,2; 2,2; 2,3; 
			Player O: 2,1; 1,2; 1,3; 3,3;

		The program identifies the draw, prints out corresponding message and returns code 3 as expected

		Output of last turn:
		4
		3   O X O
		2   O X X
		1   X O X
		0
		  0 1 2 3 4

		Player X: 1,1; 3,1; 3,2; 2,2; 2,3;
		9 turns are played. The game is a draw.



	4. Command argument: Lab3.exe TicTac
		
		The programs calls usageMsg() and prints out messages as expected with return code 1

		Output:
			This program takes in the game name as the sole parameter, and the game starts
			Usage: Lab3.exe TicTacToe


	5. Command argument: Lab3.exe TicTacToe Game
		
		The programs calls usageMsg() and prints out messages as expected with return code 1

		Output:
			This program takes in the game name as the sole parameter, and the game starts
			Usage: Lab3.exe TicTacToe

	6. Command argument: Lab3.exe
		
		The programs calls usageMsg() and prints out messages as expected with return code 1

		Output:
			This program takes in the game name as the sole parameter, and the game starts
			Usage: Lab3.exe TicTacToe
	


Notes:

	Instead of using gamepiece objects, I chose to implement the project using string objects instead, because string
		objects can perform all functions that this program requires

	In TicTacToegame.h, function getDimen() is declared and defined there because it is a short function.

	In prompt(), only the exact phrase "quit" is considered as the keyword to quit the game, i.e. case sensitive.
	When "quit" is entered, a specfic code for "quit" is returned.

	draw (): there can only be a draw when the entire inner 3 by 3 board is filled.

	The game starts with Player X

	Two class variables "playerXMoves" and "playerOMoves" are created to record their respective valid moves throughout the game.

	Any character after a valid input is ignored (i.e. 1,1,1,1,1 is accepted as a valid input with coordinate 1,1)

