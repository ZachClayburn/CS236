//
// Created by zach on 10/25/17.
//

#ifndef CS236_LAB_COLUMNNAMEPAIR_H
#define CS236_LAB_COLUMNNAMEPAIR_H

#include <string>

class ColumnNamePair {

public:

	ColumnNamePair(int columnIn = -1, std::string nameIn = "");

	int getColumn() const;

	std::string getName() const;

private:

	int column;

	std::string name;
};


#endif //CS236_LAB_COLUMNNAMEPAIR_H
