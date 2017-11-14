#include <iostream>
#include <list>
#include <fstream>
#include <set>
#include "Table.h"
#include "ColumnValueKey.h"
#include "ColumnColumnKey.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void test1() {
	//Testing the basic functionality of tableUnion two tables with one row each unioned together
	cout << "Running Test 1." << endl;
	vector<string> colName = {"Col1"};
	vector<string> row1 = {"A"};
	vector<string> row2 = {"B"};

	Table table1("Table",colName);
	Table table2("Table",colName);
	Table table3("Table",colName);

	table1.addRow(Row(row1));
	table2.addRow(Row(row2));
	table3.addRow(Row(row1));
	table3.addRow(Row(row2));

	table1.tableUnion(table2);

	if(table3.toString() == table1.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}

}

void test2(){
	//Slightly more complex test of tableUnion, multiple rows in both tables, each with multiple columns
	cout << "Running Test 2." << endl;
	vector<string> colName = {"Col1","Col2","Col3"};
	vector<string> row1 = {"A","B","C"};
	vector<string> row2 = {"B","C","D"};
	vector<string> row3 = {"C","D","E"};
	vector<string> row4 = {"D","E","F"};

	Table table1("Table",colName);
	Table table2("Table",colName);
	Table table3("Table",colName);

	table1.addRow(Row(row1));
	table1.addRow(Row(row2));
	table2.addRow(Row(row3));
	table2.addRow(Row(row4));
	table3.addRow(Row(row1));
	table3.addRow(Row(row2));
	table3.addRow(Row(row3));
	table3.addRow(Row(row4));

	table1.tableUnion(table2);

	if(table3.toString() == table1.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}

}

void test3(){
	//Test that tables with the same headers in the wrong order
	cout << "Running Test 3." << endl;

	vector<string> colNameOne = {"Col1","Col2","Col3"};
	vector<string> colNameTwo = {"Col2","Col1","Col3"};

	vector<string> row1 = {"a","b","c"};
	vector<string> row2 = {"d","e","f"};
	vector<string> row3 = {"b","a","c"};
	vector<string> row4 = {"h","g","i"};
	vector<string> row5 = {"g","h","i"};

	Table table1("Table",colNameOne);
	Table table2("Table",colNameTwo);
	Table table3("Table",colNameOne);

	table1.addRow(Row(row1));
	table1.addRow(Row(row2));

	table2.addRow(Row(row3));
	table2.addRow(Row(row4));

	table3.addRow(Row(row1));
	table3.addRow(Row(row2));
	table3.addRow(Row(row5));

	table1.tableUnion(table2);

	if(table3.toString() == table1.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}

}

void test4(){
	//Tests that join properly appends the tables' headers together
	cout << "Running test 4." << endl;

	vector<string> columnNames1 = {"Col1","Col2","Col4"};
	vector<string> columnNames2 = {"Col1","Col4","Col5","Col6"};
	vector<string> columnNames3 = {"Col1","Col2","Col4","Col5","Col6"};

	Table table1("Table",columnNames1);
	Table table2("Table",columnNames2);
	Table table3("Table",columnNames3);

	Table table4 = table1.join(table2);



	if(table3.toString() == table4.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
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

