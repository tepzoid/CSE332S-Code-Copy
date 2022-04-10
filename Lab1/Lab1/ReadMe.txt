

Author: Jinfeng Chen

CSE 332S Lab 1

This program reads in a file name as the command line argument. Then, the program:
1.Parses the strings in the text file that is separated by blank spaces
2.Prints strings that contain characters other than digits 
3.Prints non-zero integers


Possible Return Codes:
0 - Success
1 - File Cannot Open
2 - Incorrect Number of Command Line Arguments

Errors/Warnings:
	
	Signed/Unsigned mismatch C4018
		This is caused by trying to compare size_t (an unsigned int) with a looping variable (int)

	Logical Error:
		Didn't realize & string prints out the address instead of the string 

Test Cases:

1.command line argument: Lab1.exe input_file.txt text_file.txt
	Result: The program called the usage function, prints instructions, and return code 2 at exit as expected.

2.command line argument: Lab1.exe 
	Result: The program performed as expected. Called the usage function and return code 2 at exit.

3. command line argument: Lab1.exe input_file.txt
	Result: The program prints out non-numerical strings followed by numbers as expected.

	Output:
these
all
are
strings
7string
str4ing
string2
more
strings
0
1
2
3
5
7
11
13
17
19

4. command line argument: Lab1.exe input_zero.txt
	Result: The program exits as expected with code 1 (file_cannot_open) with a "File cannot open" message. The file does not exist.

5. command line argument: Lab1.exe test_file.txt
	input file: sdflkjds sdfklj 93 923 234234325-  324io 3
				dsfjk	 iofhj9 93-083490	38758374892	98343
				dfsn3]349	384723479 	9

	Result: The programs performed as expected, printing non-numerical strings followed by numbers.


----Strings contain non-numerical values are NOT considered numbers. Include "-234234", "0.3423"

----Numbers that exceed INT_MAX will be converted to INT_MAX;
		Example: input of "38758374892" will be converted to INT_MAX, i.e. 2147483647


****************************************************************
	EXTRA CREDIT

	Part 1
	[c.jinfeng@shell ~]$ ls
	Desktop  Downloads  Music  My Documents  perl5  Pictures  Public  temp  Templates  Videos  VisualSource  WINDOWS

	Part 2
	
	warning: scoped enums only available with -std=c++11 or -std=gnu++11 [enabled by default]
		 enum class arrIndex {prgm_path, input_name, total_cmd_line}; //enumeration for different array indices related to argv []

	error: ‘arrIndex’ is not a class or namespace
		 if (argc != static_cast<int>(arrIndex::total_cmd_line)) {}

	Return:
	//The program works as expected on Linux machine

	1.

		[c.jinfeng@shell lab1]$ ./LinuxLab1 input_file.txt
these
all
are
strings
7string
str4ing
string2
more
strings
0
1
2
3
5
7
11
13
17
19

	2.

	[c.jinfeng@shell lab1]$ ./LinuxLab1 test_file.txt
sdflkjds
sdfklj
234234325-
324io
dsfjk
iofhj9
93-083490
dfsn3]349
93
923
3
2147483647
98343
384723479
9
		
