//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_HEADER_H
#define CS236_LAB_HEADER_H


#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "ColumnColumnKey.h"

class Header {

public:

	Header(std::vector<std::string> colNamesIn);

	Header(std::vector<std::string> header1, std::vector<std::string> header2);

	std::vector<std::string> getColumnNames() const;

	std::vector<std::string> getReducedColumnNames(std::vector<int> columnsToKeep);

	size_t size() const;

	std::string toString();

	std::vector<ColumnColumnKey> getMatchingColumns(const Header &header);

private:

	std::vector<std::string> columnNames;

};


#endif //CS236_LAB_HEADER_H
