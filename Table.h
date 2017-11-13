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
#include "ColumnNamePair.h"

class Table {

public:

	Table(std::string nameIn = "Null", std::vector<std::string> columnNamesIn = {});

	Table(const Table& table);

	Table select(std::vector<SelectionKey*> selectionKeys);

	Table project(const std::vector<int> &columnsToKeep);

	Table rename(std::vector<ColumnNamePair> newNames);

	Table join(const Table& table);

	void tableUnion(Table table);

	void addRow(Row rowIn);

	std::string toString();

	size_t size();

	std::string getName();

	std::vector<std::string> getHeaderColumnNames() const;

private:

	struct rowComp{
		bool operator()(const Row& left, const Row& right) const {
			size_t length = left.size();
			for(size_t i = 0; i < length; i++){
				if(left.at(i) != right.at(i))
					return left.at(i) < right.at(i);
			}
			return false;
		}
	};

	std::vector<int> getNewOrder(const Table &table) const;

	std::string name;

	std::set<Row,rowComp> rows;

	Header header;

};


#endif //CS236_LAB_TABLE_H
