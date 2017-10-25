#include <iostream>
#include <list>
#include <fstream>
#include "Table.h"
#include "Row.h"
#include "ColumnValueKey.h"
#include "ColumnColumnKey.h"


void test1() {
	//This test checks if the rows are properly sorted
	std::cout << "Running Test 1" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1"};
	std::vector<std::string> row1 = {"a"};
	std::vector<std::string> row2 = {"b"};
	std::vector<std::string> row3 = {"c"};
	std::vector<std::string> row4 = {"d"};
	std::vector<SelectionKey*> keys;

	Table table(name,colNames);
	Table control(name,colNames);

	table.addRow(Row(row3));
	table.addRow(Row(row1));
	table.addRow(Row(row4));
	table.addRow(Row(row2));

	control.addRow(Row(row1));
	control.addRow(Row(row2));
	control.addRow(Row(row3));
	control.addRow(Row(row4));

	if(table.toString() == control.toString()){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}
void test2(){
	//This test checks that duplicate rows are not kept in a Table
	std::cout << "Running test 2" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1"};
	std::vector<std::string> row1 = {"a"};
	std::vector<std::string> row2 = {"b"};
	std::vector<std::string> row3 = {"c"};
	std::vector<std::string> row4 = {"d"};
	std::vector<SelectionKey*> keys;

	Table table(name,colNames);
	Table control(name,colNames);

	table.addRow(Row(row1));
	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row2));
	table.addRow(Row(row3));
	table.addRow(Row(row3));
	table.addRow(Row(row4));
	table.addRow(Row(row4));

	control.addRow(Row(row1));
	control.addRow(Row(row2));
	control.addRow(Row(row3));
	control.addRow(Row(row4));
	if(table.toString() == control.toString()){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test3(){
	//This test check the select method's basic functionality
	std::cout << "Running Test 3" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2"};
	std::vector<std::string> row1 = {"a","a"};
	std::vector<std::string> row2 = {"b","a"};
	std::vector<std::string> row3 = {"c","c"};
	std::vector<SelectionKey*> keys;
	bool failed = false;

	Table table(name,colNames);
	Table control1(name,colNames);
	Table control2(name,colNames);

	//First, we test the ColumnColumnKey
	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));

	control1.addRow(Row(row1));
	control1.addRow(Row(row3));

	//Removes any row that doesn't have a match in the first two columns
	keys.push_back(new ColumnColumnKey(0,1));

	table.select(keys);

	if(table.toString() != control1.toString()){
		failed = true;
	}

	//Now, we test a columnValueKey
	control2.addRow(Row(row1));
	keys.clear();

	//Removes any row that doesn't contain an "a" in the first column
	keys.push_back(new ColumnValueKey(0,"a"));

	table.select(keys);

	if(table.toString() != control2.toString()){
		failed = true;
	}

	if(!failed){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test4(){
	//This test checks that multiple keys can be passed at once, then tests that selecting on an empty table won't fail
	std::cout << "Running Test 4" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2"};
	std::vector<std::string> row1 = {"b","a"};
	std::vector<std::string> row2 = {"a","a"};
	std::vector<std::string> row3 = {"c","c"};
	std::vector<SelectionKey*> keys;
	bool failed = false;

	Table table(name,colNames);
	Table control1(name,colNames);
	Table control2(name,colNames);

	keys.push_back(new ColumnColumnKey(0,1));
	keys.push_back(new ColumnValueKey(0,"a"));

	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));

	control1.addRow(row2);

	table.select(keys);

	if(table.toString() != control1.toString()){
		failed = true;
	}

	keys.clear();

	keys.push_back(new ColumnValueKey(0,"A"));
	keys.push_back(new ColumnValueKey(0,"B"));

	table.select(keys);

	if(table.toString() != control2.toString()){
		failed = true;
	}

	if(!failed){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
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

