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

std::string Predicate::toString() {
	std::stringstream ss;
	ss << predicateID.toString() << '(';
	for(int i = 0; i < parameterList.size(); i++){
		ss << parameterList.at(i).toString();
		if(i < parameterList.size()-1){
			ss << ',';
		}
	}

	ss << ')';

	return ss.str();
}

void Predicate::addParameter(Lexer& lexer) {
	if(lexer.checkNextType(Token::ID)){
		parameterList.emplace_back(ID(lexer));
	}else if(lexer.checkNextType(Token::STRING)){
		parameterList.emplace_back(String(lexer));
	} else if(lexer.checkNextType(Token::ADD)||lexer.checkNextType(Token::MULTIPLY)){
		//todo set up full polymorphism for Parameter to include Operators
	}
	if(lexer.checkNextType(Token::COMMA)){
		lexer.getNext(Token::COMMA);
		addParameter(lexer);
	}
}
