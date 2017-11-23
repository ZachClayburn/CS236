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

std::string HeadPredicate::getID() {
	return headID.toString();
}

std::vector<int> HeadPredicate::getColumnsToKeep(std::vector<std::string> headerCols) {
	std::vector<int> colsToKeep(IDList.size(),-1);

	int outerCol = 0;
	for(auto &ID : IDList){
		int innerCol = 0;
		std::string IDString = ID.toString();
		while(IDString != headerCols.at(innerCol)) {
			innerCol++;
			if(innerCol >= headerCols.size()){
				throw ID.getToken();
			}
		}
		colsToKeep.at(outerCol) = innerCol;
		outerCol++;
	}

	return colsToKeep;
}

std::vector<std::string> HeadPredicate::getIdStrings() {
	std::vector<std::string> IDStrings(IDList.size(),"");
	int ii = 0;
	for(auto &ID : IDList){
		IDStrings.at(ii) = ID.toString();
		ii++;
	}
	return IDStrings;
}
