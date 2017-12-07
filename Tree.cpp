//
// Created by zach on 12/7/17.
//

#include "Tree.h"

void Tree::setRecursive() {
	recursive = true;
}

bool Tree::isRecursive() const {
	return recursive;
}

bool Tree::operator==(const Tree &rhs) {
	if((*this).size() != rhs.size() || this->isRecursive() != rhs.isRecursive()){
		return false;
	}
	auto thisIt = this->begin();
	auto rhsIt = rhs.begin();
	while (thisIt != this->end()){
		if(*thisIt != *rhsIt){
			return false;
		}
		thisIt++;
		rhsIt++;
	}
	return true;
}
