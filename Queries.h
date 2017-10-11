//
// Created by zach on 10/3/17.
//

#ifndef CS236_LAB_QUERYCLASS_H
#define CS236_LAB_QUERYCLASS_H

#include "Lexer.h"
#include "Predicate.h"

class Queries {

public:

	Queries(Lexer& lexer);

	std::string toString();

private:

	std::vector<Predicate> queryList;

	void addQuery(Lexer& lexer);

};


#endif //CS236_LAB_QUERYCLASS_H
