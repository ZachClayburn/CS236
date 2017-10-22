#include <iostream>
#include <list>
#include <fstream>
#include "Table.h"
#include "Row.h"

int main() {

	std::string name = "Test";
	std::list<std::string> colNames = {"1","2","3"};
	std::list<std::string> row = {"1","2","3"};

	Table table(name,colNames);
	table.addRow(Row(row));

	std::cout << table.getName();

	return 0;
}

