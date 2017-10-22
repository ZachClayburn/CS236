//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_TABLE_H
#define CS236_LAB_TABLE_H


#include <string>
#include <list>
#include "Header.h"
#include "Row.h"

class Table {

public:

	Table(std::string nameIn, std::list<std::string> columnNamesIn);

	void addRow(Row rowIn);

	std::string getName();

private:

	std::string name;

	std::list<Row> rows;

	Header header;

};


#endif //CS236_LAB_TABLE_H
