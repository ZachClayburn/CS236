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

	std::string resultString = ""
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
	//
	cout << "Running Test 2." << endl;
}

void test3(){
	//
	cout << "Running Test 3." << endl;
}

void test4(){
	//
	cout << "Running test 4." << endl;
}

void test5(){
	//
	cout << "Running test 5." << endl;
}

void test6(){
	//
	cout << "Running test 6." << endl;
}

void test7(){
	//
	cout << "Running test 7." << endl;
}

void test8(){
	//
	cout << "Running test 8." << endl;
}

void test9(){
	//
	cout << "Running test 9." << endl;
}

void test10(){
	//
	cout << "Running test 10." << endl;
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

