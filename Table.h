//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_TABLE_H
#define CS236_LAB_TABLE_H


#include <string>
#include <list>
#include <vector>
#include <sstream>
#include "Header.h"
#include "Row.h"
#include "SelectionKey.h"

class Table {

public:

	Table(std::string nameIn, std::list<std::string> columnNamesIn);

	Table(const Table& table);

	Table select(std::vector<SelectionKey*> selectionKeys);

	std::vector<std::string> getHeaderColumnNames();

	void addRow(Row rowIn);

	std::string toString();

	std::string getName();

private:

	std::string name;

	std::list<Row> rows;

	Header header;

};


#endif //CS236_LAB_TABLE_H
