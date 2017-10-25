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

std::string Table::toString() {
	std::stringstream ss;
	ss << name << std::endl << header.toString() << std::endl;


	for(auto it = rows.begin(); it != rows.end(); it++){
		ss << it->toString() << std::endl;
	}

	return ss.str();
}

Table Table::select(std::vector<SelectionKey*> selectionKeys) {
	Table copy(*this);
	for(auto &key : selectionKeys){
		for(auto it = copy.rows.begin(); it != copy.rows.end(); it++){
			if(!key->checkMatch(*it)) {
				//std::cout << "Removing " << it->toString() << std::endl;
				copy.rows.erase(it);
			}
		}

	}
	return copy;
}

std::string Table::getName() {
	return name;
}

Table Table::project(std::set<int> columnsToKeep) {
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

std::vector<std::string> Table::getHeaderColumnNames() {
	return header.getColumnNames();
}

void Table::addRow(Row rowIn) {

	if(rowIn.size() != header.size()){
		throw "Row is incorrect size!";
	}

	rows.insert(rowIn);
}
