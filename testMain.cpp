#include <iostream>
#include <list>
#include <fstream>
#include <set>
#include <vector>
#include "Graph.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void test1() {
	//Test that nodes are added and printed properly
	cout << "Running Test 1." << endl;
	Graph graph(4);

	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(1,2);
	graph.addEdge(1,3);
	graph.addEdge(2,3);

	string resultString = ""
			"R0:R1,R2\n"
			"R1:R2,R3\n"
			"R2:R3\n"
			"R3:\n";

	if (graph.toString() == resultString){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test2(){
	//Test if Graph can properly reverse
	cout << "Running Test 2." << endl;

	Graph graph(4);

	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	graph.addEdge(3,0);

	Graph reverseGraph = graph.reverse();

	string testString = ""
			"R0:R3\n"
			"R1:R0\n"
			"R2:R1\n"
			"R3:R2\n";

	if(reverseGraph.toString() == testString){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test3(){
	//A more complicated reversal
	cout << "Running Test 3." << endl;

	Graph graph(8);

	graph.addEdge(0,0);
	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(0,3);
	graph.addEdge(5,3);
	graph.addEdge(6,7);

	Graph testGraph = graph.reverse();

	string testString = ""
			"R0:R0\n"
			"R1:R0\n"
			"R2:R0\n"
			"R3:R0,R5\n"
			"R4:\n"
			"R5:\n"
			"R6:\n"
			"R7:R6\n";

	if(testGraph.toString() == testString){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test4(){
	//Simple test of the topoOrdering function on a single cyclic graph
	cout << "Running test 4." << endl;

	Graph graph(4);

	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	graph.addEdge(3,0);

	std::stack<int> order = graph.topoOrdering();
	std::stack <int> trueOrder;
	trueOrder.push(3);
	trueOrder.push(2);
	trueOrder.push(1);
	trueOrder.push(0);

	if(order == trueOrder){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test5(){
	//Testing another topographical ordering
	cout << "Running test 5." << endl;

	Graph graph(8);

	graph.addEdge(0,3);
	graph.addEdge(1,3);
	graph.addEdge(2,6);
	graph.addEdge(3,5);
	graph.addEdge(3,7);
	graph.addEdge(5,7);

	std::stack<int> order = graph.topoOrdering();
	std::stack<int> trueOrder;
	trueOrder.push(7);
	trueOrder.push(5);
	trueOrder.push(3);
	trueOrder.push(0);
	trueOrder.push(1);
	trueOrder.push(6);
	trueOrder.push(2);
	trueOrder.push(4);

	if(order == trueOrder){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test6(){
	//Test that SCC are computed correctly just 3 components, linearly connected
	cout << "Running test 6." << endl;

	Graph graph(3);

	graph.addEdge(0,1);
	graph.addEdge(1,2);

	Forest forest = graph.getSCC();

	Forest control;

	control.emplace();//This is to create a new SCC, so I can add elements to it
	control.back().insert(2);
	control.emplace();
	control.back().insert(1);
	control.emplace();
	control.back().insert(0);

	if(forest == control){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}

}

void test7(){
	//A more complicated SCC which includes a single cycle
	cout << "Running test 7." << endl;

	Graph graph(4);

	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	graph.addEdge(3,0);

	Forest forest = graph.getSCC();

	Forest control;

	control.emplace();
	control.back().insert(0);
	control.back().insert(1);
	control.back().insert(2);
	control.back().insert(3);
	control.back().setRecursive();

	if(forest == control){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test8(){
	//Two SCC that are actually two disjoint graphs
	cout << "Running test 8." << endl;

	Graph graph(6);

	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,0);
	graph.addEdge(3,4);
	graph.addEdge(4,5);
	graph.addEdge(5,3);

	Forest forest = graph.getSCC();

	Forest control;

	control.emplace();
	control.back().setRecursive();
	control.back().insert(3);
	control.back().insert(4);
	control.back().insert(5);
	control.emplace();
	control.back().setRecursive();
	control.back().insert(0);
	control.back().insert(1);
	control.back().insert(2);

	if(forest == control){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test9(){
	//A single circuit of for vertices, each with another pendant vertex.
	cout << "Running test 9." << endl;

	Graph graph(8);
	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	graph.addEdge(3,0);
	graph.addEdge(0,4);
	graph.addEdge(1,5);
	graph.addEdge(2,6);
	graph.addEdge(3,7);

	Forest forest = graph.getSCC();

	Forest control;
	control.emplace();
	control.back().insert(7);
	control.emplace();
	control.back().insert(6);
	control.emplace();
	control.back().insert(5);
	control.emplace();
	control.back().insert(4);
	control.emplace();
	control.back().insert(3);
	control.back().insert(2);
	control.back().insert(1);
	control.back().insert(0);
	control.back().setRecursive();

	if(forest == control){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test10(){
	//One last Test of a SCC, this time with several SCC of varying complexity
	cout << "Running test 10." << endl;

	Graph graph(9);
	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(1,2);
	graph.addEdge(1,5);
	graph.addEdge(2,3);
	graph.addEdge(3,6);
	graph.addEdge(4,0);
	graph.addEdge(4,1);
	graph.addEdge(5,4);
	graph.addEdge(6,6);
	graph.addEdge(6,8);
	graph.addEdge(7,8);
	graph.addEdge(8,7);

	Forest forest = graph.getSCC();

	Forest control;
	control.emplace();
	control.back().setRecursive();
	control.back().insert(7);
	control.back().insert(8);
	control.emplace();
	control.back().setRecursive();
	control.back().insert(6);
	control.emplace();
	control.back().insert(3);
	control.emplace();
	control.back().insert(2);
	control.emplace();
	control.back().setRecursive();
	control.back().insert(0);
	control.back().insert(1);
	control.back().insert(4);
	control.back().insert(5);

	if(forest == control){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

int main(){
	try { test1(); }
	catch (...) { std::cout << "Crashed on test 1!" << std::endl;}
	try { test2(); }
	catch (...) { std::cout << "Crashed on test 2!" << std::endl;}
	try { test3(); }
	catch (...) { std::cout << "Crashed on test 3!" << std::endl;}
	try { test4(); }
	catch (...) { std::cout << "Crashed on test 4!" << std::endl;}
	try { test5(); }
	catch (...) { std::cout << "Crashed on test 5!" << std::endl;}
	try { test6(); }
	catch (...) { std::cout << "Crashed on test 6!" << std::endl;}
	try { test7(); }
	catch (...) { std::cout << "Crashed on test 7!" << std::endl;}
	try { test8(); }
	catch (...) { std::cout << "Crashed on test 8!" << std::endl;}
	try { test9(); }
	catch (...) { std::cout << "Crashed on test 9!" << std::endl;}
	try { test10(); }
	catch (...) { std::cout << "Crashed on test 10!" << std::endl;}
}

