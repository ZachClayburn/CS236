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
	if(lexer.checkNextType(Token::LEFT_PAREN))
		addScheme(lexer);
}
