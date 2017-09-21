//
// Created by zach on 9/18/17.
//

#include <iostream>
#include "Token.h"
#include "InputChars.h"

int main(int nargin, char* args[]){

	InputChars inputChars(args[1]);
	char thing = ' ';
	int lineNum = 0;

	while(!inputChars.isEOF()){
		int temp = inputChars.getCurLine();
		if(temp != lineNum){
			lineNum = temp;
			std::cout << lineNum << ' ';
		}
		thing = inputChars.getNext();
		std::cout << thing;
	}

	inputChars.moveToPosition(26);
	while(!inputChars.isEOF()){
		int temp = inputChars.getCurLine();
		if(temp != lineNum){
			lineNum = temp;
			std::cout << lineNum << ' ';
		}
		thing = inputChars.getNext();
		std::cout << thing;
	}



	return 0;
}