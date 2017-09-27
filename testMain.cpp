//
// Created by zach on 9/18/17.
//

#include <iostream>
#include "Token.h"
#include "InputChars.h"

int main(int nargin, char* args[]){

	std::string string = "Hello, world!";

	for(auto &point : string){
		std::cout << point << std::endl;
	}

	return 0;
}