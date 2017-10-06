//
// Created by zach on 9/29/17.
//

#ifndef CS236_LAB_PARSER_H
#define CS236_LAB_PARSER_H

#include "Lexer.h"
#include "SchemeClass.h"

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
	 * @param lexer a Lexer object that contains Tokens to be parset
	 */
	Parser(Lexer& lexer);

private:


};


#endif //CS236_LAB_PARSER_H
