//
// Created by zach on 10/9/17.
//

#ifndef CS236_LAB_RULE_H
#define CS236_LAB_RULE_H


#include "Lexer.h"
#include "ID.h"
#include "HeadPredicate.h"
#include "Predicate.h"

class Rule {

public:

	/**
	 * Constructs a Rule object and parses the Rule.
	 *
	 * Constructs a Rule and parses through the Tokens in lexer
	 * @param lexer The Lexer object containing the Tokens
	 */
	Rule(Lexer& lexer);

	/**
	 * Returns a string formatted for printing.
	 *
	 * Get a string of the contents of the Rule, formatted for printing
	 * @return A std::string formatted for printing.
	 */
	std::string toString();

private:

	HeadPredicate head;

	std::vector<Predicate> predicateList;

	void addPredicate(Lexer& lexer);
};


#endif //CS236_LAB_RULE_H
