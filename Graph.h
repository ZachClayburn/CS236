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

	bool addEdge(int node, int edge);

	std::string toString();

private:

	std::vector<Node> nodes;

};


#endif //CS236_LAB_GRAPH_H
