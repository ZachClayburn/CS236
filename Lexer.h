//
// Created by zach on 9/18/17.
//

#ifndef CS236_LAB_LEXICALANALIZER_H
#define CS236_LAB_LEXICALANALIZER_H

#include <vector>
#include "Token.h"
#include "InputChars.h"

class Lexer {
public:

	/**
	 * Constructs a Lexer object.
	 *
	 * The constructor creates the Lexer object and parses through all of the input in the InputChars, creating tokens
	 * out of all of the contents
	 * @param input An InputChars object containing the contents of a file read in already
	 * @returns A Lexer object
	 */
	Lexer(InputChars input);


private:
	/**
	 * A vector containing all of the tokens from the file
	 */
	std::vector<Token> tokens;



};


#endif //CS236_LAB_LEXICALANALIZER_H
