#include <iostream>
#include <list>
#include <fstream>
#include "Table.h"
#include "Row.h"
#include "ColumnValueKey.h"
#include "ColumnColumnKey.h"

void printList(std::list<std::string> list){
	for(auto it = list.begin(); it != list.end(); it++){
		std::cout << *it << std::endl;
	}
}

void test1() {

	std::string name = "Test";
	std::list<std::string> colNames = {"Col1","Col2","Col3"};
	std::vector<std::string> row1 = {"1","2","3"};
	std::vector<std::string> row2 = {"a","b","c"};
	std::vector<std::string> row3 = {"Zach","Meg","Zach"};
	std::vector<SelectionKey*> keys;
	keys.push_back(new ColumnValueKey(0,"1"));
	keys.push_back(new ColumnColumnKey(0,1));


	Table table1(name,colNames);
	
	table1.addRow(Row(row1));
	table1.addRow(Row(row2));
	table1.addRow(Row(row3));

	std::cout << table1.toString();

	Table table2 = table1.select(keys);
}
void test2(){

}

void test3(){

}

void test4(){

}

void test5(){

}

void test6(){

}

void test7(){

}

void test8(){

}

void test9(){

}

void test10(){

}

int main(){
	try { test1(); }
	catch (...) { std::cerr << "Crashed on test 1!" << std::endl;}
	try { test2(); }
	catch (...) { std::cerr << "Crashed on test 2!" << std::endl;}
	try { test3(); }
	catch (...) { std::cerr << "Crashed on test 3!" << std::endl;}
	try { test4(); }
	catch (...) { std::cerr << "Crashed on test 4!" << std::endl;}
	try { test5(); }
	catch (...) { std::cerr << "Crashed on test 5!" << std::endl;}
	try { test6(); }
	catch (...) { std::cerr << "Crashed on test 6!" << std::endl;}
	try { test7(); }
	catch (...) { std::cerr << "Crashed on test 7!" << std::endl;}
	try { test8(); }
	catch (...) { std::cerr << "Crashed on test 8!" << std::endl;}
	try { test9(); }
	catch (...) { std::cerr << "Crashed on test 9!" << std::endl;}
	try { test10(); }
	catch (...) { std::cerr << "Crashed on test 10!" << std::endl;}
}

