//
// Created by zach on 10/9/17.
//

#include "Predicate.h"

Predicate::Predicate(Lexer &lexer) :
		predicateID(lexer){
	lexer.getNext(Token::LEFT_PAREN);
	addParameter(lexer);
	lexer.getNext(Token::RIGHT_PAREN);
}

/*
Predicate::~Predicate() {
	for (auto &parameter : parameterList)
		delete parameter;

}
*/

std::string Predicate::toString() {
	std::stringstream ss;
	ss << predicateID.toString() << '(';
	for(int i = 0; i < parameterList.size(); i++){
		ss << parameterList.at(i)->toString();
		if(i < parameterList.size()-1){
			ss << ',';
		}
	}

	ss << ')';

	return ss.str();
}

void Predicate::addParameter(Lexer& lexer) {
	if(lexer.checkNextType(Token::ID))
		parameterList.push_back(new ID(lexer));
	else if(lexer.checkNextType(Token::STRING))
		parameterList.push_back(new String(lexer));
	else
		parameterList.push_back(new Expression(lexer));

	if(lexer.checkNextType(Token::COMMA)){
		lexer.getNext(Token::COMMA);
		addParameter(lexer);
	}
}
