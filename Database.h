//
// Created by zach on 10/30/17.
//

#ifndef CS236_LAB_DATABASE_H
#define CS236_LAB_DATABASE_H

#include <map>
#include "Parser.h"
#include "Table.h"
#include "Graph.h"

class Database {

public:

	Database(Parser *parserIn);

	void printDatabase();

private:

	void addSchemes();

	void addRows();

	void evalRules(Rules *rules, Tree &SCC);

	void evalRules();

	void evalQueries();

	std::map<std::string,Table> tables;

	Parser* parser;

	size_t rulePasses = 0;

};


#endif //CS236_LAB_DATABASE_H
