//
// Created by zach on 10/9/17.
//

#include "Parameter.h"

Parameter::Parameter(Lexer &lexer, Token::types type):
		token(lexer.getNext(type)){}

std::string Parameter::toString() {
	return token.getString();
}

