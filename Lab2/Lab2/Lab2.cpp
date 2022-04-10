// Lab2.cpp 
// 
// This file contains the 'main' function. It parse the text file 
// to extract gameboard dimensions and individual game pieces;
// Store all game pieces in a vector;
// Print the gameboard with all game pieces
// 
// Author: Jinfeng Chen   c.jinfeng@wustl.edu


#include "Header.h"
#include "Gameboard.h"

using namespace std;

int main(int argc, char * argv[])
{
    //TEST

    cout << "23" << setw(10) << "77" <<  "64" << endl;
    //So setw(n) only apply a string of spaces of length n once



    int nameIndex = static_cast<int>(arrIndex::prgm_path);
    
    //Checks if only one command argument has been passed to the program
    if (argc == static_cast<int>(arrIndex::total_cmd_line)) {

        ifstream ifs;

        //calculate the index of the input file name, aka the first command line argument
        unsigned int index = static_cast<unsigned int>(arrIndex::input_name);
        ifs.open(argv[index]);


        //Check if the file is opened correctly
        if (ifs.is_open()) {
            
            unsigned int width = 0;
            unsigned int height = 0;

            int read_dim_val = static_cast<int>(read_dim(ifs, width, height));//get the return value of read_dim()

            //if read_dim() cannot extract dimension, more extraction attempts follow
            if (read_dim_val == static_cast<int>(suc_fail_code::cannot_extract_dimen)) {

                while (read_dim_val == static_cast<int>(suc_fail_code::cannot_extract_dimen)) {

                    read_dim_val = static_cast<int>(read_dim(ifs, width, height));

                    //Stop trying to extract dimension when extraction is successful or there is no more line to read
                    //Return dimen_never_found error if there is no more line to read
                    //Continue to the next part of the program if success code is returned
                    if ((read_dim_val == static_cast<int>(suc_fail_code::cannot_read_line))) {

                        cout << "Cannot find gameboard dimension in the file" << endl;
                        return static_cast<int>(suc_fail_code::dimen_never_found);
                    }
                   
                }
                
            }

            //Create an empty vector to hold game_piece
            vector<game_piece> gamepieceVec;

         

            game_piece empty(piece_color::no_color, " ", "");

            //Push empty games pieces to the vector
            for (unsigned int vectorNum = 0; vectorNum < width * height; ++vectorNum) {
                gamepieceVec.push_back(empty);
            }

            //read game pieces from the file stream
            if (read_piece(ifs, gamepieceVec, width, height) == static_cast<int>(suc_fail_code::cannot_find_well_formed_piece)) {

                cout << "Cannot find well-formed pieces in the file" << endl;

                return static_cast<int>(suc_fail_code::cannot_find_well_formed_piece);
            }
            //if at least one game piece definition was successfully read from the file
            //print the gameboard with all game pieces
            else
            {
                
                

                return static_cast<int>(printPieces(gamepieceVec, width, height) );
            }

            

        }
        else {
            cout << "File Cannot Be Opened" << endl;
            return static_cast<int>(suc_fail_code::file_cannot_open);

        }
    }
    else {
        
        const char infoStr[] = "<input_file.txt>";
        return usageMsg(argv[nameIndex], infoStr);
    }

   

    
}

//Converts uppercase letters in a string to lowercase letters
string toLowercase(string& input) {
    const int toLower = 32; //a constant that converts uppercase letters to lowercase letters--ASCII

    string output;
    char temp = '0';//a temporary char that hold converted character
    for (char c : input) {
        if ( (c >= 'A') && (c <= 'Z')) //Checks if char c is an uppercase letter
        {
            temp = c + toLower;
            output += temp;
        }
        else {
            output += c;
        }
    }
    return output;
}

//Prints usage message to prompt users use the program ns a correct way; 
//Gives a return value to indicate which type of failure occured

/// <summary>
/// 
/// </summary>
/// <param name="program_name"></param>
/// <param name="more_info"></param>
/// <returns></returns>
int usageMsg(const char* program_name, const char * more_info) 
{
    //strcmp returns 0 if two strings are the same
    int strSame = 0;

    

    cout << "This program takes in a file name as the sole parameter, and parses the file" << endl;
    cout << "Usage: " << program_name << " " << more_info << endl;

    return static_cast<int>(suc_fail_code::incorrect_usage);
        
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
