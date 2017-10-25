//
// Created by zach on 10/21/17.
//

#include "ColumnValueKey.h"

ColumnValueKey::ColumnValueKey(int columnIn, std::string valueIn) {
	column = columnIn;
	value = valueIn;
}

bool ColumnValueKey::checkMatch(Row &row) {
	return (row.at(column) == value);
}
