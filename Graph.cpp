//
// Created by zach on 12/5/17.
//

#include "Graph.h"

Graph::Graph(int size) : nodes(size,Node()){

}

bool Graph::addEdge(int startNode, int endNode) {
	if(endNode >= nodes.size()){
		throw std::out_of_range("Node not in graph");
	}
	bool isAdded = nodes.at(startNode).addEdge(endNode);
}

std::string Graph::toString() {
	std::stringstream ss;
	for(int i = 0; i < nodes.size(); i++){
		ss << 'R' << i << ':' << nodes.at(i).toString() << '\n';
	}
	return ss.str();
}

Graph Graph::reverse() {
	Graph graph((int)nodes.size());

	for(int startNode = 0; startNode < nodes.size(); startNode++){
		const std::set<int>& edges = nodes.at(startNode).getEdges();
		for (auto &endNode : edges){
			graph.addEdge(endNode,startNode);
		}
	}

	return graph;
}
