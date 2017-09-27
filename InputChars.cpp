//
// Created by zach on 9/20/17.
//

#include "InputChars.h"

InputChars::InputChars(const char* fileName) {

	std::ifstream infile;
	char* buffer;
	infile.open(fileName);

	infile.seekg(0,infile.end);
	long length = infile.tellg();
	infile.seekg(0,infile.beg);
	buffer = new char[length];
	infile.read(buffer,length);
	delete[] buffer;

	this->chars = std::string(buffer);
	this->curLine = 1;
	this->curPos = 0;

}

char InputChars::getNext() {

	char value = chars.at(curPos);
	if(value == '\n'){
		curLine++;
	}

	curPos++;

	return value;
}

int InputChars::getLine() const {
	return this->curLine;
}

unsigned long InputChars::getPosition() const {
	return this->curPos;
}

void InputChars::moveToPosition(int index) {

	for(curPos = curLine = 0;curPos <= index;curPos++){
		char temp = chars.at(curPos);
		if(temp == '\n'){
			curLine++;
		}
	}
	curLine++;
}

bool InputChars::isEOF() {
	return (curPos >= chars.size());
}

char InputChars::peekNext() {
	return chars.at(curPos);
}
