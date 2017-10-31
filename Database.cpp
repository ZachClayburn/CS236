//
// Created by zach on 10/30/17.
//

#include "Database.h"

Database::Database(Parser* parser) {
	addSchemes(parser);
	addRows(parser);
	evalQueries(parser);
}

void Database::printDatabase() {

	for(auto &table : tables){
		std::cout << table.first << std::endl;
		std::cout << table.second.toString() << std::endl;
	}

}

void Database::addSchemes(Parser *parser) {
	Schemes* schemes = parser->getSchemes();

	while(schemes->moreSchemes()){
		std::string name = schemes->getSchemeName();
		std::pair<std::string,Table> temp = {name,Table(name,schemes->getSchemeColumnNames())};
		tables.insert(temp);
	}


}

void Database::addRows(Parser *parser) {
	Facts* facts = parser->getFacts();

	while(facts->moreFacts()){
		std::string name = facts->getFactScheme();
		tables.at(name).addRow(Row(facts->getFactContents()));
	}

}

void Database::evalQueries(Parser *parser) {
	Queries* queries = parser->getQueries();

	while(queries->moreQueries()){
		std::string query = queries->getFullQuery();
		Table temp = tables.at(queries->getQueryName());
		std::vector<SelectionKey*> keys = queries->getSelectionKeys();
		temp = temp.select(keys);
		std::vector<int> columnsToKeep = queries->getColumnsToKeep();
		temp = temp.project(columnsToKeep);
//		std::vector<ColumnNamePair> renames = queries->getRenames(columnsToKeep);
//		temp.rename(renames);

		size_t size = temp.size();
		std::cout << query;
		if(size == 0){
			std::cout << " No" << std::endl;
		}else {
			std::cout << " Yes(" << size << ")" << std::endl;
			std::cout << temp.toString();
		}
	}

}
