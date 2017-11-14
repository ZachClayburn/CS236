//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_COLUMNCOLUMNKEY_H
#define CS236_LAB_COLUMNCOLUMNKEY_H


#include "SelectionKey.h"

class ColumnColumnKey : public SelectionKey {

public:

	ColumnColumnKey(int column1In, int column2In);

	virtual bool checkMatch(const Row &row) const override;

	virtual bool checkMatch(const Row &row1, const Row &row2) const;

	int getRemoveColumns() const;

private:

	int column1;

	int column2;

};


#endif //CS236_LAB_COLUMNCOLUMNKEY_H
