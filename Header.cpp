//
// Created by zach on 10/21/17.
//

#include "Header.h"

Header::Header(std::list<std::string> colNamesIn) {
	for(auto &colName : colNamesIn){
		columnNames.push_back(colName);
	}

}

std::string Header::toString() {
	std::stringstream ss;

	for(auto &name : columnNames){
		ss << name << ' ';
	}

	return ss.str();
}

std::vector<std::string> Header::getColumnNames() {
	return columnNames;
}

size_t Header::size() {
	return columnNames.size();
}
