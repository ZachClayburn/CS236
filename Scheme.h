//
// Created by zach on 10/5/17.
//

#ifndef CS236_LAB_SCHEME_H
#define CS236_LAB_SCHEME_H

#include <vector>
#include "ID.h"
#include "Lexer.h"

class Scheme {
public:

	/**
	 * Constructs a scheme
	 *
	 * Constructs a scheme from the Tokens in lexer
	 * @param lexer The Lexer object containing all of the Tokens
	 */
	Scheme(Lexer& lexer);

	~Scheme();

private:
	/**
	 * The ID that represents the given Scheme
	 */
	ID* schemeID;

	/**
	 * A vector of all Ids in a Scheme, should not be empty
	 */
	std::vector<ID> IDList;

	void addIDToList(Lexer& lexer);

};


#endif //CS236_LAB_SCHEME_H
