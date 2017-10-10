//
// Created by zach on 10/10/17.
//

#include "Expression.h"

Expression::Expression(Lexer &lexer) : Parameter(lexer) {
	lexer.getNext(Token::LEFT_PAREN);
	leftParam = addParameter(lexer);

	if(lexer.checkNextType(Token::MULTIPLY))
		op = new Opperator(lexer,Token::MULTIPLY);
	else
		op = new Opperator(lexer,Token::ADD);

	rightParam = addParameter(lexer);
	lexer.getNext(Token::RIGHT_PAREN);
}

Expression::~Expression() {
	delete leftParam;
	delete rightParam;
	delete op;


}

std::string Expression::toString() {//todo Properly override toString
	std::stringstream ss;

	ss << '(' << leftParam->toString() << op->toString() << rightParam->toString() << ')';

	return ss.str();
}

Parameter* Expression::addParameter(Lexer &lexer) {
	if(lexer.checkNextType(Token::ID))
		return new ID(lexer);
	else if(lexer.checkNextType(Token::STRING))
		return new String(lexer);
	else
		return new Expression(lexer);
}

