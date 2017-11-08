//
// Created by zach on 10/5/17.
//

#include "ID.h"

ID::ID(Lexer &lexer):
Parameter(lexer,Token::ID){}

Token::types ID::getType() {
	return Token::ID;
}

ID::ID(const Parameter *oldParam) : Parameter(oldParam) {}

