//
// Created by zach on 10/30/17.
//

#include "Database.h"

Database::Database(Parser *parserIn) {
	parser = parserIn;
	addSchemes();
	addRows();
	evalRules();
	evalQueries();
}

void Database::printDatabase() {

	for(auto &table : tables){
		std::cout << table.first << std::endl;
		std::cout << table.second.toString() << std::endl;
	}

}

void Database::addSchemes() {
	Schemes* schemes = parser->getSchemes();

	while(schemes->moreSchemes()){
		std::string name = schemes->getSchemeName();
		std::pair<std::string,Table> temp = {name,Table(name,schemes->getSchemeColumnNames())};
		tables.insert(temp);
	}


}

void Database::addRows() {
	Facts* facts = parser->getFacts();

	while(facts->moreFacts()){
		std::string name = facts->getFactScheme();
		tables.at(name).addRow(Row(facts->getFactContents()));
	}

}

void Database::evalRules() {
	Rules* rules = parser->getRules();
	bool isChanged;

	do {
		isChanged = false;
		while (rules->moreRules()) {
			Rule *rule = rules->getRule();
			Table ruleResult(rule->getHeadID());
			while (rule->morePredicates()) {
				Predicate *predicate = rule->getPredicate();
				Table predResult = tables.at(predicate->getIDString()).select(predicate->getSelectionKeys());
				std::vector<int> columnsToKeep = predicate->getColumnsToKeep();
				std::vector<ColumnNamePair> renames = predicate->getRenames(columnsToKeep);
				predResult = predResult.rename(renames).project(columnsToKeep);
				ruleResult = ruleResult.join(predResult);
			}
			ruleResult = ruleResult.project(rule->getColumnsToKeep(ruleResult.getHeaderColumnNames()));
			ruleResult = ruleResult.rename(rule->getRenames());
			if(tables.at(ruleResult.getName()).tableUnion(ruleResult))
				isChanged = true;
		}
	}while(isChanged);

}

void Database::evalQueries() {
	Queries* queries = parser->getQueries();

	while(queries->moreQueries()){
		std::string query = queries->getFullQuery();
		Table temp = tables.at(queries->getQueryName());
		std::vector<SelectionKey*> keys = queries->getSelectionKeys();
		temp = temp.select(keys);
		std::vector<int> columnsToKeep = queries->getColumnsToKeep();
		std::vector<ColumnNamePair> renames = queries->getRenames(columnsToKeep);
		temp = temp.rename(renames);
		temp = temp.project(columnsToKeep);

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
