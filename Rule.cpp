//
// Created by zach on 10/9/17.
//

#include "Rule.h"

Rule::Rule(Lexer &lexer):
head(lexer){
	lexer.getNext(Token::COLON_DASH);


}

std::string Rule::toString() {
	return std::__cxx11::string();
}
