//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_COLUMNVALUEKEY_H
#define CS236_LAB_COLUMNVALUEKEY_H


#include <string>
#include "SelectionKey.h"

class ColumnValueKey : public SelectionKey {

public:

	ColumnValueKey(int columnIn, std::string valueIn);

	virtual bool checkMatch(const Row &row) const override ;

private:

	int column;

	std::string value;

};


#endif //CS236_LAB_COLUMNVALUEKEY_H
