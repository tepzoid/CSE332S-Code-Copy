﻿// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"


using namespace std;

int main(int, char * argv[])
{

    const char * p = argv[0]; //Why not & argv[0]?

    while(p!='\0'){           //Why is the output like that? Isn't char * represent C-style strings?
        cout << *p << endl;
        ++p;
    }

   // cout << argv[0]<<endl;
	return 0;
}
