//
// Created by zach on 9/29/17.
//

#include "Parser.h"

Parser::Parser(Lexer &lexer) {

	schemes = new Schemes(lexer);
	//facts = NULL;
	//rules = NULL;
	//queries = NULL;

}

Parser::~Parser() {
	delete schemes;
	//delete facts;
	//delete rules;
	//delete queries;
}

std::string Parser::toString() {
	std::stringstream ss;

	ss << schemes->toString();
	//ss << facts->toString();
	//ss << rules->toString();
	//ss << queries->toString();
	//ss << domainToString(); todo create domainToString()

	return ss.str();
}