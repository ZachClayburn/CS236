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
