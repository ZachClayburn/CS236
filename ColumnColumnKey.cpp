//
// Created by zach on 10/21/17.
//

#include "ColumnColumnKey.h"

ColumnColumnKey::ColumnColumnKey(int column1In, int column2In) {
	column1 = column1In;
	column2 = column2In;

}

bool ColumnColumnKey::checkMatch(Row &row) {
	return row.at(column1) == row.at(column2);
}

