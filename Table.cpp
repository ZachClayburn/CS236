//
// Created by zach on 10/21/17.
//

#include "Table.h"

Table::Table(std::string nameIn, std::list<std::string> columnNamesIn):
header(columnNamesIn){
	name = nameIn;

}

std::string Table::getName() {
	return name;
}

void Table::addRow(Row rowIn) {

	if(rowIn.size() != header.size()){
		throw "Row is incorrect size!";
	}

	rows.push_back(rowIn);
}
