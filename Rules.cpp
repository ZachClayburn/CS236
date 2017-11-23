//
// Created by zach on 10/3/17.
//

#include "Rules.h"

Rules::Rules(Lexer &lexer) {
	lexer.getNext(Token::RULES);
	lexer.getNext(Token::COLON);
	addRule(lexer);
}

std::string Rules::toString() {
	std::stringstream ss;

	ss << "Rules(" << rulesList.size() << "):" << std::endl;

	for(auto &rule : rulesList){
		ss << "  " << rule.toString() << std:: endl;
	}

	return ss.str();
}

bool Rules::moreRules() {
	return curRule < rulesList.size();
}

Rule *Rules::getRule() {
	Rule* rValue = &(rulesList.at(curRule));
	curRule++;
	return rValue;
}

void Rules::addRule(Lexer &lexer) {
	if(lexer.checkNextType(Token::ID)){
		rulesList.emplace_back(Rule(lexer));
		lexer.getNext(Token::PERIOD);
		addRule(lexer);
	}

}
