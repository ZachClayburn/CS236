//
// Created by zach on 10/30/17.
//

#ifndef CS236_LAB_DATABASE_H
#define CS236_LAB_DATABASE_H

#include <map>
#include "Parser.h"
#include "Table.h"

class Database {

public:

	Database(Parser *parserIn);

	void printDatabase();

private:

	void addSchemes();

	void addRows();

	void evalRules();

	void evalQueries();

	std::map<std::string,Table> tables;

	Parser* parser;

};


#endif //CS236_LAB_DATABASE_H
