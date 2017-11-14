//
// Created by zach on 10/21/17.
//

#include "ColumnColumnKey.h"

ColumnColumnKey::ColumnColumnKey(int column1In, int column2In) {
	column1 = column1In;
	column2 = column2In;

}

bool ColumnColumnKey::checkMatch(const Row &row) const {
	auto one = row.at(column1);
	auto two = row.at(column2);
	return one == two;
}

bool ColumnColumnKey::checkMatch(const Row &row1, const Row &row2) const {
	return row1.at(column1) == row2.at(column2);
}

int ColumnColumnKey::getRemoveColumns() const {
	return column2;
}

