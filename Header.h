//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_HEADER_H
#define CS236_LAB_HEADER_H


#include <string>
#include <list>
#include <list>

class Header {

public:

	Header(std::list<std::string> colNamesIn);

	size_t size();

private:

	std::list<std::string> columnNames;

};


#endif //CS236_LAB_HEADER_H
