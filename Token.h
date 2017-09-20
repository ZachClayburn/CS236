//
// Created by zach on 9/18/17.
//

#ifndef CS236_LAB_TOKEN_H
#define CS236_LAB_TOKEN_H

#include <string>
#include <sstream>

class Token {

public:
	enum types {
		COMMA,
		PERIOD,
		Q_MARK,
		LEFT_PAREN,
		RIGHT_PAREN,
		COLON,
		COLON_DASH,
		MULTIPLY,
		ADD,
		SCHEMES,
		FACTS,
		RULES,
		QUERIES,
		ID,
		STRING,
		COMMENT,
		WHITESPACE,
		UNDEFINED,
		ENDOFFILE};
	/**
	 * Constructs a Token object.
	 *
	 * Constructs an object that represtens a token from a given file
	 * @param lineIn The line of the file that the token began on
	 * @param stringIn The string that the token represents
	 * @param typeIn They type of the token, taken from Token::types
	 * @returns the new Token object
	 * */
	Token(int lineIn, std::string stringIn, Token::types typeIn);

	/**
	 * Get the contents of the Token in a string.
	 *
	 * Gets a string of the contents in the form (TYPE,string,line)
	 * @return a std::string containing the tokens contents
	 */
	std::string getString();

private:
	//The string extracted as this token
	std::string string;

	//The line that the token began on
	int line;

	//The type of token
	types type;
};


#endif //CS236_LAB_TOKEN_H
