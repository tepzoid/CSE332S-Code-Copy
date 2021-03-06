#include "DisplayCommand.h"
#include "SimpleFileSystem.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fileSysPtr(fileSys) {};

int DisplayCommand::execute(string input) {

	if (input.find(" ") == -1) {
		string fileName, fileType;
		istringstream iss = istringstream(input);

		if (!(iss >> fileName)) { return notSupported; }

		AbstractFile* file_opened = fileSysPtr->openFile(fileName);
		if (file_opened == nullptr) {
			return fileNotExist;
		}

		AbstractFileVisitor* dispVisitor = new BasicDisplayVisitor();
		file_opened->accept(dispVisitor);


		delete dispVisitor;

		fileSysPtr->closeFile(file_opened);
		return successful;
	}

	else {
		string fileName, flag;
		istringstream iss = istringstream(input);

		if (!(iss >> fileName) || !(iss >> flag)) { return notSupported; }

		if (flag == "-d") {
			AbstractFile* file_opened = fileSysPtr->openFile(fileName);

			if (file_opened == nullptr) {
				return fileNotExist;
			}

			vector<char> contents = file_opened->read();

			for (char c : contents) {
			
					cout << c; 
				
			}
			cout << endl;
			fileSysPtr->closeFile(file_opened);

			return successful;

		}

		else {
			displayInfo();
			return commandNotFound;
		}
		
	}
}

void DisplayCommand::displayInfo() {
	cout << "-d displays only the data of the file, can be invoked with cat <filename> -d" << endl;
};