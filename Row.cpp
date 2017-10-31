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

std::string Row::toString(std::vector<std::string> headerNames) const {
	std::stringstream ss;

	for(int i = 0; i < contents.size(); i++){
		ss << headerNames.at(i) << '=' << contents.at(i);
		if(i < contents.size() - 1)
			ss << ", ";
	}

	return ss.str();
}

Row Row::getReducedRow(std::vector<int> columnsToKeep) const {
	std::vector<std::string> reducedNames;

	for (int toKeep : columnsToKeep) {
		reducedNames.push_back(contents.at(toKeep).data());
	}

	return Row(reducedNames);

}
