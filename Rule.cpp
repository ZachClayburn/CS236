//
// Created by zach on 10/9/17.
//

#include "Rule.h"

Rule::Rule(Lexer &lexer):
head(lexer){
	lexer.getNext(Token::COLON_DASH);
	addPredicate(lexer);

}

std::string Rule::toString() {
	std::stringstream ss;
	ss << head.toString() << " :- ";
	for(int i = 0; i < predicateList.size(); i++){
		ss << predicateList.at(i).toString();
		if(i < predicateList.size()-1){
			ss << ',';
		}
	}

	ss << '.';

	return ss.str();
}

void Rule::addPredicate(Lexer& lexer) {
	predicateList.emplace_back(Predicate(lexer));
	if(lexer.checkNextType(Token::COMMA)){
		lexer.getNext(Token::COMMA);
		addPredicate(lexer);
	}

}
