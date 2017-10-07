//
// Created by zach on 10/6/17.
//

#ifndef CS236_LAB_FACT_H
#define CS236_LAB_FACT_H


#include "Lexer.h"
#include "String.h"
#include "ID.h"

class Fact {

public:

	/**
	 * Constructs a Fact object and Parses the fact.
	 *
	 * Parses through the Tokens in lexer and adds them to the stringList
	 * @param lexer The Lexer object holding all of the Tokens
	 */
	Fact(Lexer& lexer);

	/**
	 * Get a string of the Fact's contents.
	 *
	 * Return a string of the following format for printing:
	 * FactID(string1...,stringN)
	 * @return A formated string for printing
	 */
	std::string toString();

	/**
	 * Get a vector containing the Strings of int the Fact.
	 *
	 * Gets a copy of the stringList vector, which contains all of the Strings in the Fact
	 * @return A copy of stringList
	 */
	std::vector<String> getStrings();

private:

	/**
	 * The ID of the Fact
	 */
	ID factID;

	/**
	 * A Vector of all strings in the Fact.
	 */
	std::vector<String> stringList;

	/**
	 * Adds String objects to the stringList recursively
	 *
	 * Parses through the Tokens in lexer and adds strings to the stringList
	 * @param lexer The Lexer object holding all of the Token objects
	 */
	void addString(Lexer& lexer);

};


#endif //CS236_LAB_FACT_H
