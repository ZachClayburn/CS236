//
// Created by zach on 10/3/17.
//

#ifndef CS236_LAB_QUERYCLASS_H
#define CS236_LAB_QUERYCLASS_H

#include "Lexer.h"
#include "Predicate.h"
#include "SelectionKey.h"
#include "ColumnNamePair.h"

class Queries {

public:

	Queries(Lexer& lexer);

	std::string toString();

	bool moreQueries();

	std::string getFullQuery();

	std::string getQueryName();

	std::vector<SelectionKey*> getSelectionKeys();

	std::vector<int> getColumnsToKeep();

	std::vector<ColumnNamePair> getRenames(std::vector<int> columnsToKeep);

private:

	std::vector<Predicate> queryList;

	void addQuery(Lexer& lexer);

	int curQuery = 0;

};


#endif //CS236_LAB_QUERYCLASS_H
