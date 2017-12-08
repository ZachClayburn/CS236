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
bool operator==(const Tree &lhs, const Tree &rhs) {
	if(lhs.size() != rhs.size() || lhs.isRecursive() != rhs.isRecursive()){
		return false;
	}
	auto lhsIt = lhs.begin();
	auto rhsIt = rhs.begin();
	while (lhsIt != lhs.end()){
		if(*lhsIt != *rhsIt){
			return false;
		}
		lhsIt++;
		rhsIt++;
	}
	return true;
}
