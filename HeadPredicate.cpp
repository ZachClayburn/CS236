//
// Created by zach on 10/9/17.
//

#include "HeadPredicate.h"

HeadPredicate::HeadPredicate(Lexer &lexer):
headID(lexer){
	lexer.getNext(Token::LEFT_PAREN);
	addID(lexer);
	lexer.getNext(Token::RIGHT_PAREN);

}

std::string HeadPredicate::toString() {
	std::stringstream ss;

	ss << headID.toString() << '(';
	for(int i = 0; i < IDList.size(); i++){
		ss << IDList.at(i).toString();
		if(i < IDList.size() -1){
			ss << ',';
		}
	}
	ss << ')';
	return ss.str();
}

void HeadPredicate::addID(Lexer &lexer) {
	IDList.emplace_back(ID(lexer));
	if(lexer.checkNextType(Token::COMMA)) {
		lexer.getNext(Token::COMMA);
		addID(lexer);
	}
}
