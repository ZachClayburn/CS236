//
// Created by zach on 12/5/17.
//

#ifndef CS236_LAB_GRAPH_H
#define CS236_LAB_GRAPH_H


#include <vector>
#include <string>
#include <sstream>
#include "Node.h"

class Graph {

public:

	Graph(int size = 0);

	bool addEdge(int startNode, int endNode);

	std::string toString();

	Graph reverse();

	std::vector<int> topoOrdering();

private:

	std::vector<Node> nodes;

	void dfs(std::vector<int> &ordering, int &position, int curNode = 0);

	bool isInVector(std::vector<int> &vector, int number);

};


#endif //CS236_LAB_GRAPH_H
