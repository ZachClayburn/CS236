//
// Created by zach on 10/5/17.
//

#ifndef CS236_LAB_ID_H
#define CS236_LAB_ID_H

#include "Token.h"
#include "Lexer.h"

class ID {

public:

	/**
	 * Constructs a new ID object
	 *
	 * Creates an ID object to hold an ID Token
	 * @param lexer The lexer Object that hold all the Tokens
	 */
	ID(Lexer& lexer);

private:

	Token token;

};


#endif //CS236_LAB_ID_H
