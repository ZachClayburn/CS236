#include <iostream>
#include <list>
#include <fstream>
#include <set>
#include "Table.h"
#include "ColumnValueKey.h"
#include "ColumnColumnKey.h"


void test1() {
	//This test checks if rename, then select
	std::cout << "Running Test 1" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1"};
	std::vector<std::string> newNames = {"Col2"};
	std::vector<std::string> row1 = {"a"};
	std::vector<std::string> row2 = {"b"};
	std::vector<std::string> row3 = {"c"};
	std::vector<std::string> row4 = {"d"};
	std::vector<SelectionKey*> keys = {new ColumnValueKey(0,"a")};
	std::vector<ColumnNamePair> changedName = {ColumnNamePair(0,"Col2")};

	Table table(name,colNames);
	Table control(name,newNames);


	table.addRow(Row(row1));
	table.addRow(Row(row3));
	table.addRow(Row(row2));
	table.addRow(Row(row4));

	control.addRow(Row(row1));

	Table testTable = table.rename(changedName);
	testTable = testTable.select(keys);

	if(testTable.toString(std::vector<std::string>()) == control.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test2(){
	//This test checks that you can project away every row
	std::cout << "Running test 2" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2"};
	std::vector<std::string> row1 = {"a","b"};
	std::vector<std::string> cColNames = {};
	std::vector<std::string> cRow1 = {};
	std::set<int> keys = {};

	Table table(name,colNames);
	Table control(name,cColNames);

	table.addRow(Row(row1));

	control.addRow(Row(cRow1));

	Table testTable = table.project(keys);

	if(testTable.toString(std::vector<std::string>()) == control.toString(std::vector<std::string>())){
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
	std::vector<std::string> row3 = {"b","W"};
	std::vector<std::string> row4 = {"c","c"};
	std::vector<std::string> row5 = {"c","g"};
	std::vector<SelectionKey*> keys;
	bool failed = false;

	Table table(name,colNames);
	Table control1(name,colNames);
	Table control2(name,colNames);

	//First, we test the ColumnColumnKey
	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));
	table.addRow(Row(row4));

	control1.addRow(Row(row1));
	control1.addRow(Row(row4));

	//Removes any row that doesn't have a match in the first two columns
	keys.push_back(new ColumnColumnKey(0,1));

	Table testTable = table.select(keys);

	if(testTable.toString(std::vector<std::string>()) != control1.toString(std::vector<std::string>())){
		failed = true;
	}

	//Now, we test a columnValueKey
	control2.addRow(Row(row1));
	keys.clear();

	//Removes any row that doesn't contain an "a" in the first column
	keys.push_back(new ColumnValueKey(0,"a"));

	testTable = testTable.select(keys);

	if(testTable.toString(std::vector<std::string>()) != control2.toString(std::vector<std::string>())){
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

	Table testTable = table.select(keys);

	if(testTable.toString(std::vector<std::string>()) != control1.toString(std::vector<std::string>())){
		failed = true;
	}

	keys.clear();

	keys.push_back(new ColumnValueKey(0,"A"));
	keys.push_back(new ColumnValueKey(0,"B"));

	testTable = testTable.select(keys);

	if(testTable.toString(std::vector<std::string>()) != control2.toString(std::vector<std::string>())){
		failed = true;
	}

	if(!failed){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test5(){
	//This Test checks the project method works correctly
	std::cout << "Running Test 5" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2","col3"};
	std::vector<std::string> row1 = {"b","a","1"};
	std::vector<std::string> row2 = {"a","a","2"};
	std::vector<std::string> row3 = {"c","c","3"};

	std::string controlName = "Test";
	std::vector<std::string> controlColNames = {"Col1","Col2"};
	std::vector<std::string> controlRow1 = {"b","a"};
	std::vector<std::string> controlRow2 = {"a","a"};
	std::vector<std::string> controlRow3 = {"c","c"};

	std::set<int> columnsToKeep = {0,1};

	Table table(name,colNames);
	Table control(controlName,controlColNames);

	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));

	control.addRow(Row(controlRow1));
	control.addRow(Row(controlRow2));
	control.addRow(Row(controlRow3));

	Table testTable = table.project(columnsToKeep);

	if(control.toString(std::vector<std::string>()) == testTable.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}

}

void test6(){
	//This test checks the rename method
	std::cout << "Running Test 6" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1"};
	std::vector<std::string> newColNames = {"newCol1"};
	std::vector<std::string> row1 = {"a"};
	std::vector<std::string> row2 = {"b"};
	std::vector<std::string> row3 = {"c"};
	std::vector<std::string> row4 = {"d"};
	std::vector<ColumnNamePair> newNames;

	newNames.emplace_back(0,"newCol1");

	Table table(name,colNames);
	Table control(name,newColNames);

	Table testTable = table.rename(newNames);

	if(control.toString(std::vector<std::string>()) == testTable.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test7(){
	//This test simulates a full select, project and rename
	//Test(NewName1,'B',NewName2)?
	std::cout << "Running Test 7" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2","col3"};
	std::vector<std::string> row1 = {"A","B","C"};
	std::vector<std::string> row2 = {"A","B","D"};
	std::vector<std::string> row3 = {"F","A","T"};
	std::vector<SelectionKey*> keys = {new ColumnValueKey(1,"B")};
	std::set<int> columnsToKeep = {0,2};
	std::vector<ColumnNamePair> newNames = {ColumnNamePair(0,"NewName1"),ColumnNamePair(1,"NewName2")};

	std::vector<std::string> cColNames = {"NewName1","NewName2"};
	std::vector<std::string> cRow1 = {"A","C"};
	std::vector<std::string> cRow2 = {"A","D"};

	Table table(name,colNames);
	Table control(name,cColNames);

	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));

	control.addRow(Row(cRow1));
	control.addRow(Row(cRow2));

	Table testTable = table.select(keys);
	testTable = testTable.project(columnsToKeep);
	testTable = testTable.rename(newNames);

	if(control.toString(std::vector<std::string>()) == testTable.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test8(){
	//This test simulates a full select, project and rename
	//test(NewName1,'B',NewName2)?
	std::cout << "Running Test 8" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2","Col3","Col4"};
	std::vector<std::string> row1 = {"A","B","C","Q"};
	std::vector<std::string> row2 = {"A","B","D","R"};
	std::vector<std::string> row3 = {"F","A","T","S"};
	std::vector<std::string> row4 = {"T","A","T","S"};
	std::vector<std::string> row5 = {"E","A","E","U"};
	std::vector<SelectionKey*> keys = {new ColumnValueKey(1,"A"), new ColumnColumnKey(0,2)};
	std::set<int> columnsToKeep = {0};
	std::vector<ColumnNamePair> newNames = {ColumnNamePair(0,"NewName1")};

	std::vector<std::string> cColNames = {"NewName1"};
	std::vector<std::string> cRow1 = {"T"};
	std::vector<std::string> cRow2 = {"E"};

	Table table(name,colNames);
	Table control(name,cColNames);

	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));
	table.addRow(Row(row4));
	table.addRow(Row(row5));

	control.addRow(Row(cRow1));
	control.addRow(Row(cRow2));

	Table testTable = table.select(keys);
	testTable = testTable.project(columnsToKeep);
	testTable = testTable.rename(newNames);

	if(control.toString(std::vector<std::string>()) == testTable.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}

}

void test9(){
	//This test simulates a full select, project and rename
	//Test(NewName1,NewName1,NewName2,NewName2)?
	std::cout << "Running Test 9" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2","Col3","Col4"};
	std::vector<std::string> row1 = {"A","A","D","D"};
	std::vector<std::string> row2 = {"B","B","D","D"};
	std::vector<std::string> row3 = {"Q","Q","T","G"};
	std::vector<std::string> row4 = {"A","B","C","D"};
	std::vector<std::string> row5 = {"E","E","T","T"};
	std::vector<SelectionKey*> keys = {new ColumnColumnKey(0,1),new ColumnColumnKey(2,3)};
	std::set<int> columnsToKeep = {0,2};
	std::vector<ColumnNamePair> newNames = {ColumnNamePair(0,"NewName1"),ColumnNamePair(1,"NewName2")};

	std::vector<std::string> cColNames = {"NewName1","NewName2"};
	std::vector<std::string> cRow1 = {"A","D"};
	std::vector<std::string> cRow2 = {"B","D"};
	std::vector<std::string> crow3 = {"E","T"};

	Table table(name,colNames);
	Table control(name,cColNames);

	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));
	table.addRow(Row(row4));
	table.addRow(Row(row5));

	control.addRow(Row(cRow1));
	control.addRow(Row(cRow2));
	control.addRow(Row(crow3));

	Table testTable = table.select(keys);
	testTable = testTable.project(columnsToKeep);
	testTable = testTable.rename(newNames);

	if(control.toString(std::vector<std::string>()) == testTable.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
	}
}

void test10(){
	//This test simulates a full select, project and rename
	//Test('B','A',NewName1)?
	std::cout << "Running Test 10" << std::endl;

	std::string name = "Test";
	std::vector<std::string> colNames = {"Col1","Col2","col3"};
	std::vector<std::string> row1 = {"A","B","C"};
	std::vector<std::string> row2 = {"A","B","D"};
	std::vector<std::string> row3 = {"A","A","T"};
	std::vector<std::string> row4 = {"F","B","T"};
	std::vector<std::string> row5 = {"F","B","G"};
	std::vector<SelectionKey*> keys = {new ColumnValueKey(1,"B"),new ColumnValueKey(0,"A")};
	std::set<int> columnsToKeep = {2};
	std::vector<ColumnNamePair> newNames = {ColumnNamePair(0,"NewName1")};

	std::vector<std::string> cColNames = {"NewName1"};
	std::vector<std::string> cRow1 = {"C"};
	std::vector<std::string> cRow2 = {"D"};

	Table table(name,colNames);
	Table control(name,cColNames);

	table.addRow(Row(row1));
	table.addRow(Row(row2));
	table.addRow(Row(row3));

	control.addRow(Row(cRow1));
	control.addRow(Row(cRow2));

	Table testTable = table.select(keys);
	testTable = testTable.project(columnsToKeep);
	testTable = testTable.rename(newNames);

	if(control.toString(std::vector<std::string>()) == testTable.toString(std::vector<std::string>())){
		std::cout << "Pass!" << std::endl;
	} else{
		std::cout << "Fail!" << std::endl;
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

