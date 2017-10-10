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
	for(int i = 0; i < parameterList.size(); i++){//todo Fix printing for Expressions with Operations
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
	} else if(lexer.checkNextType(Token::ADD)){//todo Make sure this works correctly
		parameterList.emplace_back(Opperator(lexer,Token::ADD));
	} else if(lexer.checkNextType(Token::MULTIPLY)){
		parameterList.emplace_back(Opperator(lexer,Token::MULTIPLY));
	}
	if(lexer.checkNextType(Token::COMMA)){
		lexer.getNext(Token::COMMA);
		addParameter(lexer);
	}
}
