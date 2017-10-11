//
// Created by zach on 10/3/17.
//

#include "Queries.h"

Queries::Queries(Lexer &lexer) {
	lexer.getNext(Token::QUERIES);
	lexer.getNext(Token::COLON);

}

std::string Queries::toString() {
	std::stringstream ss;

	ss << "Queries(" << queryList.size() << "):" << std::endl;
	for(auto &query : queryList)
		ss << "  " << query.toString();

	return ss.str();
}

void Queries::addQuery(Lexer &lexer) {
	if(lexer.checkNextType(Token::ID)){
		queryList.emplace_back(lexer);
	}

}
