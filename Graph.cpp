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

std::vector<int> Graph::topoOrdering() {
	std::vector<int> ordering(nodes.size(), -1);
	int position = nodes.size() - 1;

	for (int i = 0; i < nodes.size(); i++){
		if(!nodes.at(i).isVisited()) {
			dfs(ordering, position, i);
		}
	}
	for(auto& node : nodes){
		node.reset();
	}

	return ordering;
}

void Graph::dfs(std::vector<int> &ordering, int &position, int curNode) {
	std::set<int> currentEdges = nodes.at(curNode).getEdges();
	nodes.at(curNode).visit();
	for(auto &node : currentEdges){
		if(!nodes.at(node).isVisited()){
			dfs(ordering,position,node);
		}
	}
	ordering.at(position) = curNode;
	position--;
}

bool Graph::isInVector(std::vector<int> &vector, int number) {
	for(auto &curNumber : vector){
		if(number == curNumber){
			return true;
		} else if(curNumber == -1){
			return false;
		}
	}
	return false;
}
