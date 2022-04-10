// Lab1.cpp : This file contains the 'main' function. It parses an input text file, 
// and prints out non-numerical strings followed by numerical strings
// Author: Jinfeng Chen   c.jinfeng@wustl.edu
//
#include "Header.h"

int main(int argc, char * argv [])
{

    //Checks if only one command argument has been passed to the program
    if (argc != static_cast<int>(arrIndex::total_cmd_line)) {
        int nameIndex = static_cast<int>(arrIndex::prgm_path);
        return usageMsg(argv[nameIndex]);
    }

    vector<string> inStr; //new vector of string to store all parsed strings
    

   
   
    
    suc_fail_code returnVal = parse(inStr, argv[static_cast<int>(arrIndex::input_name)]);//the second parameter is the second command line argument,
                                                                                         //which is the file name

    if (returnVal != suc_fail_code::success) { //Check if parse() returns success; yes, continue; no, return the enumeration

        return static_cast<int>(returnVal);
    }

    vector<int> intList;//Create a vector to hold integers from the string vector


    bool allDigit = true; //Create a tracker to see if all characters in the string are digits
    
    //Nested loop to check if strings are numerical values
    for (auto & str : inStr) {
        
        for (auto& character : str) {
           
            if (isdigit(character)) {
            }
            else {
                allDigit = false;
            }

            if (allDigit == false) {
                cout << str << endl;
                break;
            }
        }

        int temp;//create a temporary integer to hold the output of istringsteam 

        //If a string is of numerical value only, it is pushed into a vector of integers
        if (allDigit == true)
        {
          
            istringstream numConvert(str);
            numConvert >> temp;
            intList.push_back(temp);

         

        }
        allDigit = true;//Reset the controlling boolean

        
    }
    
   //Print all integers in the vector intList
    for (auto & num : intList) {
        cout << num << ' ' << endl;
    }

    return static_cast<int>(suc_fail_code::success);
}

suc_fail_code parse(vector<string> & vStr, const char * fileName) {
    
    ifstream ifs;// creates an ifstream object to read in files
    ifs.open(fileName);

    


    if (ifs.is_open()){

        string temp;
        while (ifs >> temp) {       //this loop extracts all strings that are separated by white spaces and store them in a vector
            vStr.push_back(temp);
        }

        ifs.close();
        return suc_fail_code ::success;
    }
    else {
        cout << "File cannot be opened" << endl;
        return suc_fail_code::file_cannot_open;
    }

    return suc_fail_code::success;
    
}

//A usage program that tells the user the correct way to use this program
int usageMsg(const char * program_name) {
    cout << "This program takes in a file name as the sole parameter, and"
            " parses the file" <<endl;
    cout << "Usage: " << program_name << " <input_file_name>" << endl;
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
