//
// Created by zach on 9/18/17.
//

#include <iostream>
#include "Token.h"

int main(int nargin, char* args[]){

	Token token(1,"hi",Token::ADD);
	
	std::cout << token.getString() << std::endl;
	
	return 0;
}