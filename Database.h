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

	Database(Parser* parser);

private:

	void addSchemes(Parser *parser);

	void addRows(Parser *parser);

	void evalQueries(Parser *parser);

	std::map<std::string,Table> tables;

};


#endif //CS236_LAB_DATABASE_H
