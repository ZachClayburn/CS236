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
