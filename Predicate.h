//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_PREDICATE_H
#define CS236_LAB_PREDICATE_H


#include "Lexer.h"
#include "ID.h"
#include "String.h"

class Predicate {

public:

	Predicate(Lexer& lexer);

	std::string toString();

private:

	ID predicateID;

	std::vector<Parameter> parameterList;

	void addParameter(Lexer& lexer);

};


#endif //CS236_LAB_PREDICATE_H
