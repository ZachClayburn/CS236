//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_HEADER_H
#define CS236_LAB_HEADER_H


#include <string>
#include <sstream>
#include <vector>
#include <set>

class Header {

public:

	Header(std::vector<std::string> colNamesIn);

	std::vector<std::string> getColumnNames() const;

	std::vector<std::string> getReducedColumnNames(std::vector<int> columnsToKeep);

	size_t size();

	std::string toString();

private:

	std::vector<std::string> columnNames;

};


#endif //CS236_LAB_HEADER_H
