//
// Created by zach on 10/6/17.
//

#include "String.h"

String::String(Lexer &lexer):
Parameter(lexer,Token::STRING){}

Token::types String::getType() {
	return Token::STRING;
}

String::String(const Parameter *oldParam) : Parameter(oldParam) {}

