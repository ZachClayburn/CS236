//
// Created by zach on 10/25/17.
//

#include "ColumnNamePair.h"

ColumnNamePair::ColumnNamePair(int columnIn, std::string nameIn) {
	column = columnIn;
	name = nameIn;
}

int ColumnNamePair::getColumn() const {
	return column;
}

std::string ColumnNamePair::getName() const {
	return name;
}
