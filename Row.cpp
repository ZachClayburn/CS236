//
// Created by zach on 10/21/17.
//

#include "Row.h"

Row::Row(std::vector<std::string> contentsIn) {
	contents = contentsIn;

}

size_t Row::size() {
	return contents.size();
}

const std::string Row::at(int i) {
	return contents.at(i);
}
