//
// Created by zach on 10/9/17.
//

#include "Parameter.h"

Parameter::Parameter(Lexer& lexer) :
		token(0,"YouShouldNeverSeeThis!",Token::WHITESPACE) {}

Parameter::Parameter(Lexer &lexer, Token::types type):
		token(lexer.getNext(type)){}

std::string Parameter::toString() {
	return token.getString();
}

Token::types Parameter::getType() {
	if(token.toString() == "+")
		return Token::ADD;
	else if(token.toString() == "*")
		return Token::MULTIPLY;
	else
		std::cout << "There was Problem with Parameter::getType()\n";
}

