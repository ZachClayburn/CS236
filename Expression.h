//
// Created by zach on 10/10/17.
//

#ifndef CS236_LAB_EXPRESSION_H
#define CS236_LAB_EXPRESSION_H


#include "Parameter.h"
#include "Opperator.h"
#include "ID.h"
#include "String.h"

class Expression : public Parameter{

public:

	Expression(Lexer& lexer);

	Expression(const Expression *oldParam);

	virtual ~Expression();

	std::string toString() override;

private:

	Parameter* addParameter(Lexer& lexer);

	Parameter* leftParam;

	Parameter* op;

	Parameter* rightParam;

};


#endif //CS236_LAB_EXPRESSION_H
