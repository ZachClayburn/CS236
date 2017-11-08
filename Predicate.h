//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_PREDICATE_H
#define CS236_LAB_PREDICATE_H


#include <map>
#include "Lexer.h"
#include "ID.h"
#include "String.h"
#include "Opperator.h"
#include "Expression.h"
#include "ColumnColumnKey.h"
#include "ColumnValueKey.h"
#include "ColumnNamePair.h"

class Predicate {

public:

	Predicate(Lexer& lexer);

	Predicate(const Predicate &oldPredicate);

	~Predicate();

	std::string toString();

	std::string getIDString();

	std::vector<SelectionKey*> getSelectionKeys();

	std::vector<int> getColumnsToKeep();

	std::vector<ColumnNamePair> getRenames(std::vector<int> columnsToKeep);

private:

	ID predicateID;

	std::vector<Parameter*> parameterList;

	void addParameter(Lexer& lexer);

};


#endif //CS236_LAB_PREDICATE_H
