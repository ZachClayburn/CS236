//
// Created by zach on 9/30/17.
//

#include "Schemes.h"

Schemes::Schemes(Lexer &lexer) {
	lexer.getNext(Token::SCHEMES);
	lexer.getNext(Token::COLON);
	addScheme(lexer);
}

void Schemes::addScheme(Lexer &lexer) {
	schemeList.emplace_back(Scheme(lexer));
	if(lexer.checkNextType(Token::ID))
		addScheme(lexer);
}

std::string Schemes::toString() {
	std::stringstream ss;

	ss << "Schemes(" << schemeList.size() << "):" << std::endl;
	for(auto &scheme : schemeList){
		ss << "  " << scheme.toString() << std::endl;
	}

	return ss.str();
}

bool Schemes::moreSchemes() {
	return curScheme == schemeList.size() - 1;
}

std::string Schemes::getSchemeName() {
	return schemeList.at(curScheme).getname();
}

std::vector<std::string> Schemes::getSchemeColumnNames() {
	auto rvalue = schemeList.at(curScheme).getColumnNames();
	curScheme++;
	return rvalue;
}
