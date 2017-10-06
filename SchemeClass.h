//
// Created by zach on 9/30/17.
//

#ifndef CS236_LAB_PROGRAM_H
#define CS236_LAB_PROGRAM_H

#include "Token.h"
#include "Lexer.h"

/**
 * An object that represents the SchemeClass construction in the Datalog grammar.
 */
class SchemeClass {

public:
	/**
	 * Constructs a SchemeClass object and parses the schemes.
	 *
	 * Constructs a SchemeClass object and then parses through the Tokens in lexer until either all of the schemes have been
	 * parsed through, or an illegal token is read and that token is thrown
	 * @throws any illegal Token found is thrown
	 * @param lexer The Lexer object that holds all of the Token objects
	 */
	SchemeClass(Lexer& lexer);

private:

	/**
	 * Adds a scheme.
	 *
	 * Add a scheme from the Tokens in lexer and recursively continues to add more schemes
	 * @param lexer The Lexer object that holds all of the Token Objects
	 */
	void addScheme(Lexer& lexer);

};


#endif //CS236_LAB_PROGRAM_H
