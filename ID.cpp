//
// Created by zach on 10/5/17.
//

#include "ID.h"

ID::ID(Lexer &lexer):
token(lexer.getNext(Token::ID)) {

}

std::string ID::toString() {
	return token.getString();
}
