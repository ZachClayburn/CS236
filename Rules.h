//
// Created by zach on 10/3/17.
//

#ifndef CS236_LAB_RULECLASS_H
#define CS236_LAB_RULECLASS_H


#include "Lexer.h"
#include "Rule.h"

class Rules {

public:

	/**
	 * Constructs a Rules object and parses the Rules.
	 *
	 * Take the Tokens from lexer and parses through them, adding Rules to the  rulesList
	 * @param lexer The Lexer Object that holds the Tokens
	 */
	Rules(Lexer& lexer);

	/**
	 * Return a string for printing.
	 *
	 * Returns the contents of rules in the following format:
	 * Rules(numberOfRules):
	 *   Rules List
	 * @return A string formatted
	 */
	std::string toString();

	bool moreRules();

	Rule* getRule();

	void reset();

private:

	/**
	 * A vector containing all of the Rules.
	 */
	std::vector<Rule> rulesList;

	size_t curRule = 0;

	/**
	 * Adds a rule to rulesList.
	 *
	 * Adds a rule to the rulesList and checks if it should continue, the recursively continues to add rules to the
	 * rulesList
	 * @param lexer The Lexer Object holding all of the Tokens
	 */
	void addRule(Lexer& lexer);

};


#endif //CS236_LAB_RULECLASS_H
