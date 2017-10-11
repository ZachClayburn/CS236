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

	/**
	 * Get a string that contains the contents of the Parser.
	 *
	 * Generates a string that in the following format:
	 * Schemes(number of Schemes)
	 *   list of schemes
	 * Facts(number of Facts)
	 *   list of Facts
	 * Rules(number of Rules)
	 *   list of Rules
	 * Queries(number of Queries)
	 *   list of Queries
	 * Domain(size of domain)
	 *   list of strings in domain
	 * @return
	 */
	std::string toString();


private:

	Schemes* schemes;

	Facts* facts;

	Rules* rules;

	Queries* queries;

};


#endif //CS236_LAB_PARSER_H
