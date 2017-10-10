//
// Created by zach on 10/6/17.
//

#ifndef CS236_LAB_STRING_H
#define CS236_LAB_STRING_H


#include "Lexer.h"
#include "Parameter.h"

class String : public Parameter {

public:

	/**
	 * Construct a String object.
	 *
	 * Constructs a String object that is designed to hole a STRING Token
	 * @param lexer
	 */
	String(Lexer& lexer);

private:


};


#endif //CS236_LAB_STRING_H
