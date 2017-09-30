#include <iostream>
#include <vector>
#include <fstream>
#include "Lexer.h"


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
		std::cerr << "Error: This program takes exactly one argument, the file to be read." << std::endl;
		return 0;
	}

	//Validate the file is valid
	if(!validateFile(args[1])){
		std::cerr << "Bad File!" << std::endl;
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
