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
