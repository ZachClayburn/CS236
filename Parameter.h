//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_PARAMETER_H
#define CS236_LAB_PARAMETER_H


#include "Token.h"
#include "Lexer.h"

class Parameter {

public:

	/**
	 * The Constructor that Expression Calls.
	 *
	 * This is constructor fills the data member token will a meaningless token object, so that Expression is not
	 * limited by inheritance from Parameter
	 * @param lexer
	 */
	Parameter(Lexer& lexer);

	Parameter(const Parameter* oldParam);

	virtual ~Parameter(){}

	/**
	 * The constructor that String, ID or Operator calls.
	 *
	 * This is the the constructor that is called to create a String object or ID object, and stores the Token of that
	 * the Parameter represents
	 * @param lexer The Lexer object that holds all of the Tokens
	 * @param type The Token::Types that the object is going to be
	 */
	Parameter(Lexer& lexer,Token::types type);

	/**
	 * Get the Parameter's string.
	 *
	 * Get the string of the Token contained in Parameter
	 * @return The IDs string;
	 */
	virtual std::string toString();

	virtual Token::types getType();

	Token getToken() const ;

private:

	Token token;

};


#endif //CS236_LAB_PARAMETER_H
