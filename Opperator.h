//
// Created by zach on 10/10/17.
//

#ifndef CS236_LAB_OPPERATOR_H
#define CS236_LAB_OPPERATOR_H


#include "Parameter.h"

class Opperator : public Parameter{

public:

	Opperator(Lexer& lexer, Token::types type);

};


#endif //CS236_LAB_OPPERATOR_H
