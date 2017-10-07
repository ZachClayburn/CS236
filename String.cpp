//
// Created by zach on 10/6/17.
//

#include "String.h"

String::String(Lexer &lexer):
token(lexer.getNext(Token::STRING)){
}

std::string String::toString() {
	return token.getString();
}
