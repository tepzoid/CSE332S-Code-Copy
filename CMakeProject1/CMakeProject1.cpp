// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

using namespace std;

int main(int argc, char * argv[])
{
	cout << argv[0] << endl;

	int i = 9;
	cout << "value of i: " << i << endl;
	cout << "location of i: " << &i << endl;
    
	return 0;
}
