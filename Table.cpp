//
// Created by zach on 10/21/17.
//

#include "Table.h"

Table::Table(std::string nameIn, std::vector<std::string> columnNamesIn):
header(columnNamesIn){
	name = nameIn;

}

Table::Table(const Table &table): header(table.header) {
	name = table.name;
	rows = table.rows;
}

Table::Table(std::string nameIn, std::vector<std::string> columnNamesIn1, std::vector<std::string> columnNamesIn2) :
		header(columnNamesIn1,columnNamesIn2){
	name = nameIn;
}

std::string Table::toString() {

	std::vector<std::string> headerNames = header.getColumnNames();
	std::stringstream ss;

	if(!headerNames.empty()) {
		for (auto it = rows.begin(); it != rows.end(); it++) {
			ss << "  " << it->toString(headerNames) << std::endl;
		}
	}
	return ss.str();
}

Table Table::select(std::vector<SelectionKey*> selectionKeys) {
	Table copy(name,header.getColumnNames());
	for(auto it = rows.begin(); it != rows.end(); it++){
		bool keepRow = true;
		for(auto &key : selectionKeys){
			if(!key->checkMatch(*it)) {
				keepRow = false;
			}
		}
		if(keepRow)
			copy.addRow(*it);
	}
	return copy;
}

std::string Table::getName() {
	return name;
}

Table Table::project(const std::vector<int> &columnsToKeep) {
	Table copy(name,header.getReducedColumnNames(columnsToKeep));

	for(auto &row : rows){
		copy.addRow(row.getReducedRow(columnsToKeep));
	}

	return copy;
}

Table Table::rename(std::vector<ColumnNamePair> newNames) {
	std::vector<std::string> headerNames = header.getColumnNames();
	for(auto &pair : newNames){
		headerNames.at(pair.getColumn()) = pair.getName();
	}

	Table copy(*this);
	copy.header = headerNames;
	return copy;
}

std::vector<std::string> Table::getHeaderColumnNames() const {
	return header.getColumnNames();
}

bool Table::addRow(Row rowIn) {

	if(rowIn.size() != header.size()){
		throw "Row is incorrect size!";
	}

	auto result = rows.insert(rowIn);

	return result.second;
}

size_t Table::size() {
	return rows.size();
}

Table Table::join(Table table) {
	std::vector<ColumnColumnKey> matchingColumns = header.getMatchingColumns(table.header);
	std::set<int> removeColumns;
	std::vector<int> columnsToKeep;
	for(auto &key : matchingColumns){
		removeColumns.insert(key.getRemoveColumns());
	}

	for(int i = 0; i < table.header.size(); i++){
		auto check = removeColumns.insert(i);
		if(check.second){
			columnsToKeep.push_back(i);
		}
	}

	Table newTable(name,header.getColumnNames(),table.header.getReducedColumnNames(columnsToKeep));

	if(rows.empty()){
		for(auto &row : table.rows){
			newTable.addRow(row);
		}
		return newTable;
	}
	for(auto &row1 : rows) {
		for (auto &row2 : table.rows) {
			bool keepRow = true;
			for (auto &key : matchingColumns) {
				if(!key.checkMatch(row1,row2))
					keepRow = false;
			}
			if(keepRow){
				newTable.addRow(Row(row1,row2.getReducedRow(columnsToKeep)));
			}
		}
	}
	return newTable;
}

bool Table::tableUnion(Table table) {

	if(table.getHeaderColumnNames() != getHeaderColumnNames()){
		table = table.project(table.getNewOrder(*this));
	}

	bool isAdded = false;

	for(auto it = table.rows.begin(); it != table.rows.end();it++){
		if(addRow(*it)){
			isAdded = true;
		}
	}

	/*for(auto &row : table.rows){
		if(addRow(row))
			isAdded = true;
	}*/

	return isAdded;
}

std::vector<int> Table::getNewOrder(const Table &table) const {
	std::vector<std::string> masterColumnNames = table.getHeaderColumnNames();
	std::vector<std::string> thisColumnNames = getHeaderColumnNames();
	std::vector<int> newOrder(masterColumnNames.size(),-1);
	for(size_t i = 0;i < masterColumnNames.size(); i++){
		for(size_t j = 0; j < thisColumnNames.size();j++){
			if(masterColumnNames.at(i) == thisColumnNames.at(j))
				newOrder.at(i) = (int)j;
		}
	}
	return newOrder;
}

std::vector<ColumnNamePair> Table::getRenames() const {
	std::vector<std::string> headerNames = header.getColumnNames();
	std::vector<ColumnNamePair> renames(headerNames.size(),ColumnNamePair());
	for(int i = 0; i < headerNames.size(); i++){
		renames.at(i) = ColumnNamePair(i,headerNames.at(i));
	}
	return renames;
}
