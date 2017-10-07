//
// Created by zach on 10/6/17.
//

#ifndef CS236_LAB_STRING_H
#define CS236_LAB_STRING_H


#include "Lexer.h"

class String {

public:

	/**
	 * Construct a String object.
	 *
	 * Constructs a String object that is designed to hole a STRING Token
	 * @param lexer
	 */
	String(Lexer& lexer);

	/**
	 * Get the string representing the contents of this String
	 *
	 * Get the string of the STRING token in this String for printing
	 * @return a std::string containing the string of the STRING Token in this String
	 */
	std::string toString();
private:

	/**
	 * The STRING Token that this String represents
	 */
	Token token;

};


#endif //CS236_LAB_STRING_H
