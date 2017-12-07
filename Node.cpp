//
// Created by zach on 12/5/17.
//

#include "Node.h"

bool Node::addEdge(int edge) {
	auto value = edges.insert(edge);
	return value.second;
}

std::string Node::toString() {
	std::stringstream ss;

	for(auto it = edges.begin(); it != edges.end(); it++){
		ss << 'R' << *it;
		if(it != --edges.end()){
			ss << ',';
		}
	}
	return ss.str();
}

const std::set<int> &Node::getEdges() const {
	return edges;
}

void Node::visit() {
	visited = true;
}

void Node::reset() {
	visited = false;
}

bool Node::isVisited() {
	return visited;
}
