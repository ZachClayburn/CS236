//
// Created by zach on 9/30/17.
//

#ifndef CS236_LAB_PROGRAM_H
#define CS236_LAB_PROGRAM_H

#include <vector>
#include "Token.h"
#include "Lexer.h"
#include "Scheme.h"

/**
 * An object that represents the Schemes construction in the Datalog grammar.
 */
class Schemes {

public:
	/**
	 * Constructs a Schemes object and parses the schemes.
	 *
	 * Constructs a SchemeClass object and then parses through the Tokens in lexer until either all of the schemes have been
	 * parsed through, or an illegal token is read and that token is thrown
	 * @throws any illegal Token found is thrown
	 * @param lexer The Lexer object that holds all of the Token objects
	 */
	Schemes(Lexer& lexer);

	/**
	 * Get a string containing all of the Schemes.
	 *
	 * Returns a string in the following format:
	 * Schemes(number of Schemes)
	 *   list of schemes
	 * @return A string containing the Schemes
	 */
	std::string toString();

private:

	/**
	 * Adds a Scheme.
	 *
	 * Add a scheme from the Tokens in lexer and recursively continues to add more schemes
	 * @param lexer The Lexer object that holds all of the Token Objects
	 */
	void addScheme(Lexer& lexer);

	/**
	 * A vector of all of the schemes, should not be empty
	 */
	std::vector<Scheme> schemeList;

};


#endif //CS236_LAB_PROGRAM_H
