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
		for (const int &endNode : edges){
			graph.addEdge(endNode,startNode);
		}
	}

	return graph;
}

std::stack<int> Graph::topoOrdering() {
	std::stack <int> ordering;

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
	std::stack<int> ordering = reverse().topoOrdering();

	while (!ordering.empty()){
		int currentNode = ordering.top();

		if(!nodes.at(currentNode).isVisited()){
			std::stack<int> component;
			forest.emplace();
			if(dfs(component,currentNode)){
				forest.back().setRecursive();
			}
			while(!component.empty()){
				int temp = component.top();
				forest.back().insert(temp);
				component.pop();
			}
		}

		for(Node& node : nodes){
			node.newPass();
		}
		ordering.pop();
	}

	for(Node& node : nodes){
		node.reset();
	}

	return forest;
}

bool Graph::dfs(std::stack<int> &ordering, int curNode) {
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
