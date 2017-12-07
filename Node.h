//
// Created by zach on 12/5/17.
//

#ifndef CS236_LAB_NODE_H
#define CS236_LAB_NODE_H


#include <set>
#include <string>
#include <sstream>

class Node {

public:

	Node() = default;

	bool addEdge(int edge);

	std::string toString();

	const std::set<int>& getEdges() const;

	void visit();

	void reset();

	void newPass();

	int isVisited();

private:

	std::set<int> edges;

	int visited = 0;

};


#endif //CS236_LAB_NODE_H
