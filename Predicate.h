//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_PREDICATE_H
#define CS236_LAB_PREDICATE_H


#include "Lexer.h"
#include "ID.h"

class Predicate {

public:

	Predicate(Lexer& lexer);

	std::string toString();

private:

	ID predicateId;



	void addParameter();

};


#endif //CS236_LAB_PREDICATE_H
