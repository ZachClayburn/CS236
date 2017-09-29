//
// Created by zach on 9/20/17.
//

#include "InputChars.h"

InputChars::InputChars(const char* fileName) {

	std::ifstream infile;
	std::string string;

	infile.open(fileName);

	while(!infile.eof()){
		auto next = (char)infile.get();
		if(!infile.eof()) {
			string += next;
		}
	}

	this->chars = string;
	this->curLine = 1;
	this->curPos = 0;

}

char InputChars::getNext() {

	char value;
	if(!isEOF()) {
		value = chars.at(curPos);
		if (value == '\n') {
			curLine++;
		}
		curPos++;
	} else{
		std::cerr << "It reached out of bounds!!" << std::endl;
		value = '!';
	}

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
	if (!isEOF()) {
		return chars.at(curPos);
	}else{
		return (char)NULL;
	}
}
