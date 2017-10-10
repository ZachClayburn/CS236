//
// Created by zach on 10/3/17.
//

#ifndef CS236_LAB_FACTCLASS_H
#define CS236_LAB_FACTCLASS_H


#include "Lexer.h"
#include "Fact.h"
#include <algorithm>

class Facts {

public:

	/**
	 * Constructs a Facts object and parses the Facts.
	 *
	 * Parses through the Tokens in lexer until all of the Facts hav been parsed or an illegal token had been found
	 * @param lexer The Lexer Object holding all of the Tokens
	 */
	Facts(Lexer& lexer);

	/**
	 * Get a formatted string of all of the Facts for printing.
	 *
	 * Gets a string of the following format:
	 * Facts(NumberOfFacts):
	 *   list of all of the facts
	 * @return A formatted string for printing
	 */
	std::string toString();

	/**
	 * Get a formatted string for printing of the domain of the Facts.
	 *
	 * Get a string of the following format:
	 * Domain(SizeOfDomain
	 *   list of string in domain
	 *  @note The Domain is all of the strings in
	 * @return
	 */
	std::string domainTostring();

private:

	/**
	 * A vector holding all of the Facts, can be empty
	 */
	std::vector<Fact> factList;

	/**
	 * A vector containing the domain of the Facts, which is an ordered list of all of the unique Strings in the Facts
	 */
	std::vector<std::string> domain;

	/**
	 * Adds Fact object to the factList recursively.
	 *
	 * Parses through the tokens in lexer, adding Facts until there are no more Facts to parse
	 * @param lexer the Lexer object that holds all of the Tokens
	 */
	void addFact(Lexer& lexer);

	/**
	 * Collects the strings in the domain of the Facts
	 *
	 * Sorts through all of the strings in the Facts and gets all of the unique
	 */
	void buildDomain();
};


#endif //CS236_LAB_FACTCLASS_H
