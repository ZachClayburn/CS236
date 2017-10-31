//
// Created by zach on 9/29/17.
//

#include "Parser.h"

Parser::Parser(Lexer &lexer) {

	schemes = new Schemes(lexer);
	facts = new Facts(lexer);
	rules = new Rules(lexer);
	queries = new Queries(lexer);

	lexer.getNext(Token::ENDOFFILE);

}

Parser::~Parser() {
	delete schemes;
	delete facts;
	delete rules;
	delete queries;
}

std::string Parser::toString() {
	std::stringstream ss;

	ss << schemes->toString();
	ss << facts->toString();
	ss << rules->toString();
	ss << queries->toString();
	ss << facts->domainTostring();

	return ss.str();
}


Schemes *Parser::getSchemes() {
	return schemes;
}

Facts *Parser::getFacts() {
	return facts;
}

Rules *Parser::getRules() {
	return rules;
}

Queries *Parser::getQueries() {
	return queries;
}

