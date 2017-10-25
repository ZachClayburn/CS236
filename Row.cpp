//
// Created by zach on 10/21/17.
//

#include "Row.h"

Row::Row(std::vector<std::string> contentsIn) {
	contents = contentsIn;

}

size_t Row::size() const{
	return contents.size();
}

const std::string Row::at(int i) const {
	return contents.at(i);
}

std::string Row::toString() const {
	std::stringstream ss;

	for (auto &value : contents){
		ss << value << ' ';
	}

	return ss.str();
}
