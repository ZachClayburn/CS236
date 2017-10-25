//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_TABLE_H
#define CS236_LAB_TABLE_H


#include <string>
#include <vector>
#include <sstream>
#include <set>
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

	struct rowComp{
		bool operator()(const Row& left, const Row& right) const {
			size_t length = left.size();
			//todo sorting function
			for(size_t i = 0; i < length; i++){
				if(left.at(i) != right.at(i))
					return left.at(i) < right.at(i);
			}
			return false;
		}
	};

	std::string name;

	std::set<Row,rowComp> rows;

	Header header;

};


#endif //CS236_LAB_TABLE_H
