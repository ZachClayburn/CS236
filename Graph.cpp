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

std::stack<int> Graph::topoOrdering() {
	std::stack<int> ordering;
	int position = nodes.size() - 1;

	for (int i = 0; i < nodes.size(); i++){
		if(!nodes.at(i).isVisited()) {
			dfs(ordering, i);
		}
	}
	for(auto& node : nodes){
		node.reset();
	}

	return ordering;
}

void Graph::dfs(std::stack<int> &ordering, int curNode) {
	std::set<int> currentEdges = nodes.at(curNode).getEdges();
	nodes.at(curNode).visit();
	for(auto &node : currentEdges){
		if(!nodes.at(node).isVisited()){
			dfs(ordering,node);
		}
	}
	ordering.push(curNode);
}
