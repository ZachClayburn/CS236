#include <iostream>
#include <vector>
#include <fstream>
//#include <ctime>
#include "Lexer.h"
#include "Parser.h"
#include "Database.h"

/**
 * Validates that file exists
 *
 * This function will attempt to open the file to verify that it exists
 * @param fileName The name of the file to be validated
 * @return true if the file exists, false otherwise
 */
bool validateFile(const char* fileName);

int main(int nargin, char* args[]) {
//	std::clock_t startTime, endTime;
//	startTime = std::clock();

	//Variable declaration
	Parser* parser = nullptr;
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
	//lexer.printTokens();

	try {
		parser = new Parser(lexer);

	} catch (Token& token){
		std::cout << "Failure!" << std::endl;
		std::cout << "  " << token.toString();
		delete parser;
		return 0;
	}

	try {
		Database database(parser);
	}catch (Token token){
		std::cout << "Error in The following Token during evaluation: " << token.toString() << std::endl;
	}
	delete parser;

//	endTime = std::clock();
//
//	double seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
//
//	std::cout << "Process finished after " << seconds << " Seconds." << std::endl;

	return 0;
}

bool validateFile(const char *fileName) {

	std::ifstream fs;
	fs.open(fileName);
	bool tf = fs.is_open();
	fs.close();
	return tf;
}
