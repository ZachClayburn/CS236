//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_HEADPREDICATE_H
#define CS236_LAB_HEADPREDICATE_H


#include "Lexer.h"
#include "ID.h"

class HeadPredicate {

public:

	HeadPredicate(Lexer& lexer);

	std::string toString();

	std::string getID();

	std::vector<int> getColumnsToKeep(std::vector<std::string> headerCols);

	std::vector<std::string> getIdStrings();

private:

	ID headID;

	std::vector<ID> IDList;

	void addID(Lexer& lexer);
};


#endif //CS236_LAB_HEADPREDICATE_H
