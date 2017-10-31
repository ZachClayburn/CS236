//
// Created by zach on 10/21/17.
//

#include <set>
#include "Header.h"

Header::Header(std::vector<std::string> colNamesIn) {
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

std::vector<std::string> Header::getReducedColumnNames(std::vector<int> columnsToKeep) {
	std::vector<std::string> reducedNames;

	for (int toKeep : columnsToKeep) {
		reducedNames.push_back(columnNames.at(toKeep).data());
	}

	return reducedNames;
}
