// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"


using namespace std;

int main(int argc, char * argv[])
{

    auto p = *argv; //Why not & argv[0]?

//    while(*p!='\0'){           //Why is the output like that? Isn't char * represent C-style strings?
//        cout << *p << endl;
//        ++p;
//    }


    for(int i = 0; i < argc; i++) {
        while (*p != '\0') {
            cout << *p << endl;
            ++p;
        }
        ++argv;
        p = * argv;
    }


	return 0;
}
