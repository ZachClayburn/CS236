//
// Created by zach on 10/5/17.
//

#include "Scheme.h"

Scheme::Scheme(Lexer &lexer) {
	schemeID = new ID(lexer);
	lexer.getNext(Token::LEFT_PAREN);
	IDList.emplace_back(ID(lexer));
	addIDToList(lexer);
	lexer.getNext(Token::RIGHT_PAREN);

}

void Scheme::addIDToList(Lexer &lexer) {
	lexer.getNext(Token::COMMA);
	IDList.emplace_back(ID(lexer));
	if(lexer.checkNextType(Token::COMMA))
		addIDToList(lexer);
}

Scheme::~Scheme() {

}

std::string Scheme::toString() {
	std::stringstream ss;

	ss << schemeID->toString() << '(';
	for(int i = 0; i < IDList.size(); i++){
		ss << IDList.at(i).toString();
		if(i < IDList.size() - 1){
			ss << ',';
		}
	}
	ss << ')';

	return ss.str();
}
