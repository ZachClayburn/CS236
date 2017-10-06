//
// Created by zach on 9/18/17.
//

#include <iostream>
#include "Token.h"

Token::Token(int lineIn, std::string stringIn,Token::types typeIn){

	this->line = lineIn;
	this->string = stringIn;
	this->type = typeIn;

	if(type == Token::ID){
		if(string == "Schemes"){
			type = Token::SCHEMES;
		}else if(string == "Facts"){
			type = Token::FACTS;
		}else if(string == "Rules"){
			type = Token::RULES;
		}else if(string == "Queries"){
			type = Token::QUERIES;
		}
	}


}

std::string Token::toString()const{

	std::stringstream ss;
	std::string typeString;

	switch (this->type){

		case COMMA:         typeString = "COMMA";       break;
		case PERIOD:        typeString = "PERIOD";      break;
		case Q_MARK:        typeString = "Q_MARK";      break;
		case LEFT_PAREN:    typeString = "LEFT_PAREN";  break;
		case RIGHT_PAREN:   typeString = "RIGHT_PAREN"; break;
		case COLON:         typeString = "COLON";       break;
		case COLON_DASH:    typeString = "COLON_DASH";  break;
		case MULTIPLY:      typeString = "MULTIPLY";    break;
		case ADD:           typeString = "ADD";         break;
		case SCHEMES:       typeString = "SCHEMES";     break;
		case FACTS:         typeString = "FACTS";       break;
		case RULES:         typeString = "RULES";       break;
		case QUERIES:       typeString = "QUERIES";     break;
		case ID:            typeString = "ID";          break;
		case STRING:        typeString = "STRING";      break;
		case COMMENT:       typeString = "COMMENT";     break;
		case WHITESPACE:    typeString = "WHITESPACES"; break;
		case UNDEFINED:     typeString = "UNDEFINED";   break;
		case ENDOFFILE:     typeString = "EOF";         break;
	}

	ss << '(' << typeString << ",\"" << this->string << "\"," << this->line << ')';


	return ss.str();
}

Token::types Token::getType()const{
	return type;
}

void Token::setType(types typeIn){
	type = typeIn;
}

std::string Token::getString() {
	return string;
}
