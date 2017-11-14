//
// Created by zach on 10/21/17.
//

#include <set>
#include "Header.h"

Header::Header(std::vector<std::string> colNamesIn): columnNames(colNamesIn) {}

Header::Header(std::vector<std::string> header1, std::vector<std::string> header2) : columnNames(header1.size()+header2.size(),""){
	size_t i = 0;
	for(auto &name : header1){
		columnNames.at(i) = name;
		i++;
	}
	for(auto &name : header2){
		columnNames.at(i) = name;
		i++;
	}
}

std::string Header::toString() {
	std::stringstream ss;

	for(auto &name : columnNames){
		ss << name << ' ';
	}

	return ss.str();
}

std::vector<std::string> Header::getColumnNames() const{
	return columnNames;
}

size_t Header::size() const {
	return columnNames.size();
}

std::vector<std::string> Header::getReducedColumnNames(std::vector<int> columnsToKeep) {
	std::vector<std::string> reducedNames;

	for (int toKeep : columnsToKeep) {
		reducedNames.push_back(columnNames.at(toKeep).data());
	}

	return reducedNames;
}

std::vector<ColumnColumnKey> Header::getMatchingColumns(const Header &header) {
	std::vector<ColumnColumnKey> matchingColumns;
	for(size_t i = 0; i < columnNames.size(); i++){
		for(size_t j = 0; j < header.size(); j++){
			if(columnNames.at(i) == header.columnNames.at(j))
				matchingColumns.emplace_back(i,j);
		}
	}
	return matchingColumns;
}
