//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_ROW_H
#define CS236_LAB_ROW_H


#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class Row {

public:

	Row(std::vector<std::string> contentsIn);

	size_t size() const;

	const std::string at(int i) const;

	std::string toString() const ;

private:

	std::vector<std::string> contents;
};


#endif //CS236_LAB_ROW_H
