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

bool Parser::moreSchemes() {
	return schemes->moreSchemes();
}

std::string Parser::getSchemeName() {
	return schemes->getSchemeName();
}

std::vector<std::string> Parser::getSchemeColumns() {
	return schemes->getSchemeColumnNames();
}

bool Parser::moreFacts() {
	return facts->moreFacts();
}

std::string Parser::getFactScheme() {
	return facts->getFactScheme();
}

std::vector<std::string> Parser::getFactColumns() {
	facts->getFactContents();
}
