//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_PARAMETER_H
#define CS236_LAB_PARAMETER_H


#include "Token.h"
#include "Lexer.h"

class Parameter {

public:

	Parameter(Lexer& lexer,Token::types type);

	/**
 * Get the Parameter's string.
 *
 * Get the string of the Token contained in Parameter
 * @return The IDs string;
 */
	std::string toString();

private:

	Token token;

};


#endif //CS236_LAB_PARAMETER_H
