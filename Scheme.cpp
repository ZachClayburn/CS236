//
// Created by zach on 10/5/17.
//

#include "Scheme.h"

Scheme::Scheme(Lexer &lexer):
schemeID(lexer){
	lexer.getNext(Token::LEFT_PAREN);
	addIDToList(lexer);
	lexer.getNext(Token::RIGHT_PAREN);

}

Scheme::~Scheme() {

}

std::string Scheme::toString() {
	std::stringstream ss;

	ss << schemeID.toString() << '(';
	for(int i = 0; i < IDList.size(); i++){
		ss << IDList.at(i).toString();
		if(i < IDList.size() - 1){
			ss << ',';
		}
	}
	ss << ')';

	return ss.str();
}

void Scheme::addIDToList(Lexer &lexer) {
	IDList.emplace_back(ID(lexer));
	if(lexer.checkNextType(Token::COMMA)) {
		lexer.getNext(Token::COMMA);
		addIDToList(lexer);
	}
}

std::string Scheme::getname() {
	return schemeID.toString();
}

std::vector<std::string> Scheme::getColumnNames() {

	std::vector<std::string> rvalue;

	for(auto &ID : IDList){
		rvalue.push_back(ID.toString());
	}

	return rvalue;
}
