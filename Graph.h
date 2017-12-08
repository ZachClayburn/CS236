//
// Created by zach on 12/5/17.
//

#ifndef CS236_LAB_GRAPH_H
#define CS236_LAB_GRAPH_H


#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include "Node.h"
#include "Forest.h"

class Graph {

public:

	Graph(int size = 0);

	bool addEdge(int startNode, int endNode);

	std::string toString();

	Graph reverse();

	std::stack<int> topoOrdering();

	Forest getSCC();

private:

	std::vector<Node> nodes;

	bool dfs(std::stack<int> &ordering, int curNode);

};


#endif //CS236_LAB_GRAPH_H
