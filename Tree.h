//
// Created by zach on 12/7/17.
//

#ifndef CS236_LAB_TREE_H
#define CS236_LAB_TREE_H


#include <queue>
#include <set>

class Tree : public std::set<int>{

public:

	void setRecursive();

	bool isRecursive() const;

	bool operator==(const Tree &rhs);

private:

	bool recursive = false;

};


#endif //CS236_LAB_TREE_H
