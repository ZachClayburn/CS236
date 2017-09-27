#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Lexer.h"
#include "InputChars.h"

using std::cout;
using std::endl;

/**
 * Validates that file exists
 *
 * This function will attempt to open the file to verify that it exists
 * @param fileName The name of the file to be validated
 * @return true if the file exists, false otherwise
 */
bool validateFile(const char* fileName);

int main(int nargin, char* args[]) {

	//Variable declaration

	//Validate the number of arguments passed in
	if(nargin != 2){
		cout << "Error: This program takes exactly one argument, the file to be read." << endl;
		return 0;
	}

	//Validate the file is valid
	if(!validateFile(args[1])){
		cout << "Bad File!" << endl;
		return 0;
	}


	Lexer lexer(args[1]);

	//Requirement for Project1
	lexer.printTokens();

	return 0;
}

bool validateFile(const char *fileName) {

	std::ifstream fs;
	bool tf = false;
	fs.open(fileName);
	tf = fs.is_open();
	fs.close();
	return tf;
}
