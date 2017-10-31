//
// Created by zach on 10/3/17.
//

#ifndef CS236_LAB_QUERYCLASS_H
#define CS236_LAB_QUERYCLASS_H

#include "Lexer.h"
#include "Predicate.h"
#include "SelectionKey.h"

class Queries {

public:

	Queries(Lexer& lexer);

	std::string toString();

	bool moreQueries();

	std::string getFullQuery();

	std::string getQueryName();

	std::vector<SelectionKey*> getSelectionKeys();

private:

	std::vector<Predicate> queryList;

	void addQuery(Lexer& lexer);

	int curQuery;

};


#endif //CS236_LAB_QUERYCLASS_H
