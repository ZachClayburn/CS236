//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_ROW_H
#define CS236_LAB_ROW_H


#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <set>

class Row {

public:

	Row(std::vector<std::string> contentsIn);

	Row(Row row1, Row row2);

	Row getReducedRow(std::vector<int> columnsToKeep) const ;

	size_t size() const;

	const std::string at(size_t i) const;

	std::string toString(std::vector<std::string> headerNames) const;

private:

	std::vector<std::string> contents;
};


#endif //CS236_LAB_ROW_H
