//
// Created by zach on 9/29/17.
//

#ifndef CS236_LAB_PARSER_H
#define CS236_LAB_PARSER_H

#include "Lexer.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"

/**
 * This class parses the tokens from the Lexer
 */
class Parser {

public:

	/**
	 * Constructs a Parser object.
	 *
	 * Constructs a Parser object and attempts to parse the Tokens in lexer
	 * @throws Token objects that violate the Datalog grammar
	 * @param lexer a Lexer object that contains Tokens to be parsed
	 */
	Parser(Lexer& lexer);

	~Parser();

	//todo Make destructors work

private:

	Schemes* schemes;

	//Facts* facts;

	//Rules* rules;

	//Queries* queries;

};


#endif //CS236_LAB_PARSER_H
