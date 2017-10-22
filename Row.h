//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_ROW_H
#define CS236_LAB_ROW_H


#include <list>
#include <string>

class Row {

public:

	Row(std::list<std::string> contentsIn);

	size_t size();

private:

	std::list<std::string> contents;
};


#endif //CS236_LAB_ROW_H
