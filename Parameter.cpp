//
// Created by zach on 10/9/17.
//

#include "Parameter.h"

Parameter::Parameter(Lexer& lexer) :
		token(0,"YouShouldNeverSeeThis!",Token::WHITESPACE) {}

Parameter::Parameter(Lexer &lexer, Token::types type):
		token(lexer.getNext(type)){}

Parameter::Parameter(const Parameter *oldParam) :
		token(oldParam->token){}

std::string Parameter::toString() {
	return token.getString();
}

Token::types Parameter::getType() {
	auto string = token.toString();
	if(string == "+")
		return Token::ADD;
	else if(string == "*")
		return Token::MULTIPLY;
	else
		return Token::WHITESPACE;
}

Token Parameter::getToken() const {
	return token;
}

