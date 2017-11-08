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

void Table::addRow(Row rowIn) {

	if(rowIn.size() != header.size()){
		throw "Row is incorrect size!";
	}

	rows.insert(rowIn);
}

size_t Table::size() {
	return rows.size();
}

Table Table::join(const Table &table) {
	return Table();
}

void Table::tableUnion(const Table &table) {

	if(table.getHeaderColumnNames() != getHeaderColumnNames()){
		//todo come up with a sort function using project to change the column order
		std::cout << "Error: Unioning tables with non-matching column names!" << std::endl;
	}

	for(auto &row : table.rows){
		addRow(row);
	}

}
