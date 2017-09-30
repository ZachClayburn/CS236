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
	this->Pos = 0;

}

char InputChars::getNext() {

	char value;
	if(!isEOF()) {
		value = chars.at(Pos);
		if (value == '\n') {
			curLine++;
		}
		Pos++;
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
	return this->Pos;
}

void InputChars::moveToPosition(int index) {

	for(Pos = curLine = 0;Pos <= index;Pos++){
		char temp = chars.at(Pos);
		if(temp == '\n'){
			curLine++;
		}
	}
	curLine++;
}

bool InputChars::isEOF() {
	return (Pos >= chars.size());
}

char InputChars::peekNext() {
	if (!isEOF()) {
		return chars.at(Pos);
	}else{
		return (char)NULL;
	}
}
