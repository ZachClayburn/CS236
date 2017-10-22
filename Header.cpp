//
// Created by zach on 10/21/17.
//

#include "Header.h"

Header::Header(std::list<std::string> colNamesIn) {
	for(auto &colName : colNamesIn){
		columnNames.push_back(colName);
	}

}

size_t Header::size() {
	return columnNames.size();
}
