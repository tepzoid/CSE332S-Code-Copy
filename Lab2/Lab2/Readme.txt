
Author: Jinfeng Chen   c.jinfeng@wustl.edu

CSE 332S Lab 2

This program reads in a file name as the only command line argument. Then, the program:
1. Parse the text file to extract gameboard dimensions and individual game pieces
2. Store all game pieces in a vector
3. Print the gameboard with all game pieces

Possible Return Values:
0 - Success
1 - File Cannot Open
2 - Incorrect Number of Command Line Arguments
3 - Cannot Extract Gameboard Dimension from a Line
4 - Cannot Read a Line from the Open File
5 - Cannot Find Well-Formed Game Pieces 
6 - Size of Vector Does Not Match Gameboard Size
7 - Cannot Find Gameboard Dimension from the File



Errors/Warnings:


	Error	C3646	'name': unknown override specifier	
		Solved by adding std:: in front of functions/commands

	Error	C2065	'game_piece': undeclared identifier
		Solved by deleting incldue# commands in header file; caused by header file loop

	Error	C3861	'toLowercase': identifier not found	
		Solved by changing which header file to include; do not put header file in header file unless have to 

	Error	C2059	syntax error: '['	
		Solved by using the correct syntax to declare and initialize a C-style string; char temp [] = "eg";

	Warning C4805: '==': unsafe mix of type 'int' and type 'bool' in operation
		Later learned that strcmp() has return type int instead of bool

	Use unsigned int as loop variable make it impossible to reach below 0; use int next time

	Warning	C26451	Arithmetic overflow: Using operator '*' on a 4 byte value and then casting the result to a 8 byte value. Cast the value to the wider type before calling operator
	'*' to avoid overflow (io.2).	
		Caused by comparing unsigned long long value with int value; choose to cast the int to unsigned long long
	



Test Cases:
	
	1. Command line argument: Lab2.exe gomoku.txt
			The program prints out alternating board pattern as expected with exit code 0

			  O   O   O   O
			O   O   O   O
			 O   O   O   O


			X   X   X   X
			  X   X   X   X
			X   X   X   X

	2. Command line argument: Lab2.ex tic-tac-toe.txt
			The program prints out a gameboard with only Xs as expected with exit code 0

			X X X
			  X
			X

	3. Command line argument: Lab2.exe gomoku.tx
			The program returns expected error message ""File Cannot Be Opened" and error code 1

	4. Command line argument: Lab2.exe
			The program calls usage function and returns expected message and error code

			Output:
			This program takes in a file name as the sole parameter, and parses the file
			Usage: Lab2.exe <input_file.txt>

	5. Command line argument: Lab2.exe gomoku.ext tic-tac-toe.txt
			Same as above

	6. Command line argument: Lab2.exe no-dimen-test.txt
		input file content:
			blue Os O 0 1 
			blue Os O 1 0 
			red Xs X 0 2
			red Xs X 1 1
			red Xs X 1 2

		The program returns an error message (""Cannot find gameboard dimension in the file") 
		and the expected error code.

	7. Command line argument: Lab2.exe blankline-test.txt
		input file content:
				(blank lines with tabs and spaces)		
				(blank lines with tabs and spaces)	
			3 3
			red Xs X 1 1
			red Xs X 1 2
			red Xs X 2 2
			blue Os O 0 1 
			blue Os O 1 0 
			red Xs X 0 2

		The program extracts dimensions as expected and prints the output correctly.

	8. Command line argument: Lab2.exe all-bad-pieces.txt
		input file content:
			3 4
			blue O 0 ' 
			ble Os O a 0 
			*ed 12 X 0 2
			re= Xs X 1 1
			test_bug

		The program returns error message "Cannot find well-formed pieces in the file" 
		and error code 5 as expected


	9. Command line argument: Lab2.exe bad-formatted.txt
		input file content:
		2 3
		blue Os O 0 1 
		blue -s O 1 0 
		red Xs X 0 x
		red Xs 1 1
		red Xs X 1 2
		red Xs X 0 0

		The program skips over badly formatted lines and works as expected.

			output:
			  X

			X



	
		

-----Any color that is not red, black, white, or no_color is considered as invalid_color



	

