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

	vector<string> columnNames1 = {"Col1","Col2","Col3"};
	vector<string> columnNames2 = {"Col1","Col4","Col5","Col6"};
	vector<string> columnNames3 = {"Col1","Col2","Col3","Col4","Col5"};

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
	//Testing a simple join, same columns with everything matching, nothing should change
	cout << "Running test 5." << endl;

	vector<string> columnNames1 = {"Col1","Col2"};
	vector<string> columnNames2 = {"Col1","Col2"};

	vector<string> row1 = {"a","b"};
	vector<string> row2 = {"c","d"};

	Table table1("Table",columnNames1);
	Table table2("Table",columnNames2);

	table1.addRow(row1);
	table1.addRow(row2);

	table2.addRow(row1);
	table2.addRow(row2);

	Table table3 = table1.join(table2);



	if(table3.toString() == table1.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test6(){
	//Same columns but different rows, should return an empty table
	cout << "Running test 6." << endl;

	vector<string> columnNames1 = {"Col1","Col2"};
	vector<string> columnNames2 = {"Col1","Col2"};
	vector<string> columnNames3 = {"Col1","Col2"};

	vector<string> row1 = {"a","b"};
	vector<string> row2 = {"c","d"};

	Table table1("Table",columnNames1);
	Table table2("Table",columnNames2);
	Table table3("Table",columnNames3);

	table1.addRow(row1);

	table2.addRow(row2);

	Table table4 = table1.join(table2);

	if(table3.toString() == table4.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test7(){
	//Testing multiple columns in both tables with one column in common, multiple matches
	cout << "Running test 7." << endl;

	vector<string> colNames1 = {"Col1","Col2","Col3","Col4"};
	vector<string> colNames2 = {"Col1","Col5","Col3"};
	vector<string> colNames3 = {"Col1","Col2","Col3","Col4","Col5"};

	vector<string> row11 = {"a","b","c","d"};
	vector<string> row12 = {"a","e","c","f"};
	vector<string> row13 = {"p","q","r","s"};

	vector<string> row21 = {"a","b","c"};
	vector<string> row22 = {"a","q","c"};

	vector<string> row31 = {"a","b","c","d","b"};
	vector<string> row32 = {"a","b","c","d","q"};
	vector<string> row33 = {"a","e","c","f","b"};
	vector<string> row34 = {"a","e","c","f","q"};

	Table table1("Table",colNames1);
	Table table2("Table",colNames2);
	Table table3("Table",colNames3);

	table1.addRow(Row(row11));
	table1.addRow(Row(row12));
	table1.addRow(Row(row13));

	table2.addRow(Row(row21));
	table2.addRow(Row(row22));

	table3.addRow(Row(row31));
	table3.addRow(Row(row32));
	table3.addRow(Row(row33));
	table3.addRow(Row(row34));

	Table table4 = table1.join(table2);

	if(table3.toString() == table4.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test8(){
	//Joining columns with multiple single column rows
	cout << "Running test 8." << endl;

	vector<string> colNames = {"Col1"};

	vector<string> row1 = {"a"};
	vector<string> row2 = {"b"};
	vector<string> row3 = {"c"};
	vector<string> row4 = {"d"};

	Table table1("Table",colNames);
	Table table2("Table",colNames);
	Table table3("Table",colNames);

	table1.addRow(Row(row1));
	table1.addRow(Row(row2));
	table1.addRow(Row(row3));

	table2.addRow(Row(row2));
	table2.addRow(Row(row4));

	table3.addRow(Row(row2));

	Table table4 = table1.join(table2);

	if(table3.toString() == table4.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test9(){
	//Joining tables with matching columns, but one table is empty
	cout << "Running test 9." << endl;

	vector<string> colNames = {"Col1","Col2"};

	vector<string> row1 = {"a","b"};
	vector<string> row2 = {"c","d"};
	vector<string> row3 = {"e","f"};

	Table table1("Table",colNames);
	Table table2("Table",colNames);

	table1.addRow(Row(row1));
	table1.addRow(Row(row2));
	table1.addRow(Row(row3));

	Table table3 = table1.join(table2);

	if(table3.toString() == table2.toString()){
		cout << "Pass!" << endl;
	} else{
		cout << "Fail!" << endl;
	}
}

void test10(){
	//Joining two tables with no common columns
	cout << "Running test 10." << endl;

	vector<string> colNames1 = {"Col1","Col2"};
	vector<string> colNames2 = {"Col3","Col4"};
	vector<string> colNames3 = {"Col1","Col2","Col3","Col4"};

	vector<string> row11 = {"a","b"};
	vector<string> row12 = {"c","d"};
	vector<string> row13 = {"e","f"};

	vector<string> row21 = {"1","2"};
	vector<string> row22 = {"3","4"};
	vector<string> row23 = {"5","6"};

	vector<string> row31 = {"a","b","1","2"};
	vector<string> row32 = {"a","b","3","4"};
	vector<string> row33 = {"a","b","5","6"};
	vector<string> row34 = {"c","d","1","2"};
	vector<string> row35 = {"c","d","3","4"};
	vector<string> row36 = {"c","d","5","6"};
	vector<string> row37 = {"e","f","1","2"};
	vector<string> row38 = {"e","f","3","4"};
	vector<string> row39 = {"e","f","5","6"};

	Table table1("Table",colNames1);
	Table table2("Table",colNames2);
	Table table3("Table",colNames3);

	table1.addRow(Row(row11));
	table1.addRow(Row(row12));
	table1.addRow(Row(row13));

	table2.addRow(Row(row21));
	table2.addRow(Row(row22));
	table2.addRow(Row(row23));

	table3.addRow(Row(row31));
	table3.addRow(Row(row32));
	table3.addRow(Row(row33));
	table3.addRow(Row(row34));
	table3.addRow(Row(row35));
	table3.addRow(Row(row36));
	table3.addRow(Row(row37));
	table3.addRow(Row(row38));
	table3.addRow(Row(row39));

	Table table4 = table1.join(table2);

	if(table3.toString() == table4.toString()){
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

