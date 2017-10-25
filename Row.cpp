//
// Created by zach on 10/21/17.
//

#include <set>
#include "Row.h"

Row::Row(std::vector<std::string> contentsIn) {
	contents = contentsIn;

}

size_t Row::size() const{
	return contents.size();
}

const std::string Row::at(size_t i) const {
	return contents.at(i);
}

std::string Row::toString() const {
	std::stringstream ss;

	ss << "  ";

	for (auto &value : contents){
		ss << value << ' ';
	}

	return ss.str();
}

Row Row::getReducedRow(std::set<int> columnsToKeep) const {
	std::vector<std::string> reducedNames;

	for (int toKeep : columnsToKeep) {
		reducedNames.push_back(contents.at(toKeep).data());
	}

	return Row(reducedNames);

}
