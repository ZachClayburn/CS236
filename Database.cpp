//
// Created by zach on 10/30/17.
//

#include "Database.h"

Database::Database(Parser* parser) {
	addSchemes(parser);
	addRows(parser);
	evalQueries(parser);
}

void Database::addSchemes(Parser *parser) {
	while(parser->moreSchemes()){
		std::string name = parser->getSchemeName();
		std::pair<std::string,Table> temp = {name,Table(name,parser->getSchemeColumns())};
		tables.insert(temp);
	};


}

void Database::addRows(Parser *parser) {

}

void Database::evalQueries(Parser *parser) {

}
