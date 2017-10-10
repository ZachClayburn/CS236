//
// Created by zach on 10/6/17.
//

#include "Fact.h"

Fact::Fact(Lexer &lexer):
factID(lexer){
	lexer.getNext(Token::LEFT_PAREN);
	addString(lexer);
	lexer.getNext(Token::RIGHT_PAREN);
	lexer.getNext(Token::PERIOD);

}

std::string Fact::toString() {
	std::stringstream ss;
	ss << factID.toString() << '(';
	for(int i = 0; i < stringList.size(); i++){
		ss << stringList.at(i).toString();
		if(i < stringList.size()-1){
			ss << ',';
		}
	}
	ss << ").";
	return ss.str();
}

std::vector<String> Fact::getStrings() {
	return stringList;
}

void Fact::addString(Lexer &lexer) {
	stringList.emplace_back(String(lexer));
	if(lexer.checkNextType(Token::COMMA)){
		lexer.getNext(Token::COMMA);
		addString(lexer);
	}

}
