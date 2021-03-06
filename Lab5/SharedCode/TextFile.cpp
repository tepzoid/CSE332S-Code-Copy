//  Define the TextFile class here
#pragma once

#include "TextFile.h"
#include <iostream>
#include "AbstractFileVisitor.h"
#include <exception>

TextFile::TextFile(std::string s) : fileName(s) {

};

unsigned int TextFile::getSize() {
	return static_cast<unsigned int>(content.size());
}

std::string TextFile::getName() {
	return fileName;
}

int TextFile::write(std::vector<char> v) {
	
	content = v;
	return 0;
}

int TextFile::append(std::vector<char> v) {
	
	for (auto i : v) {
		content.push_back(i);
	}
	return 0;

}

std::vector<char> TextFile::read() {

	return content;

}

void TextFile::accept(AbstractFileVisitor* filePtr) {
	filePtr->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string fileName) {
	try {
		TextFile* newCopy = new TextFile(fileName);
		newCopy->write(content);

		return newCopy;
	}
	catch(std::bad_alloc){
		std::cout << "Bad allocation error, file creation failture" << std::endl;
		return nullptr;
	}
}