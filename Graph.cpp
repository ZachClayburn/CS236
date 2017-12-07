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

std::queue<int> Graph::topoOrdering() {
	std::queue<int> ordering;

	for (int i = 0; i < nodes.size(); i++){
		if(!nodes.at(i).isVisited()) {
			dfs(ordering, i);
		}
	}
	for(Node& node : nodes){
		node.reset();
	}

	return ordering;
}

Forest Graph::getSCC() {
	Forest forest;
	std::queue<int> ordering = reverse().topoOrdering();

	while (!ordering.empty()){
		int currentNode = ordering.front();

		if(!nodes.at(currentNode).isVisited()){
			std::queue<int> component;
			forest.emplace();
			if(dfs(component,currentNode)){
				forest.front().setRecursive();
			}
			while(!component.empty()){
				int temp = component.front();
				forest.front().insert(temp);
			}
		}

		for(Node& node : nodes){
			node.newPass();
		}
		ordering.pop();
	}

	return forest;
}

bool Graph::dfs(std::queue<int> &ordering, int curNode) {
	bool isRecursive = false;
	std::set<int> currentEdges = nodes.at(curNode).getEdges();
	nodes.at(curNode).visit();
	for(const int &node : currentEdges){
		if(!nodes.at(node).isVisited()){
			if(dfs(ordering,node)){
				isRecursive = true;
			}
		} else if(nodes.at(node).isVisited() == 2){
			isRecursive = true;
		}
	}
	ordering.push(curNode);
	return isRecursive;
}
