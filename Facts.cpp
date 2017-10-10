//
// Created by zach on 10/3/17.
//

#include "Facts.h"

Facts::Facts(Lexer &lexer) {
	lexer.getNext(Token::FACTS);
	lexer.getNext(Token::COLON);
	if(lexer.checkNextType(Token::ID))
		addFact(lexer);
	buildDomain();
}

std::string Facts::toString() {
	std::stringstream ss;
	ss << "Facts(" << factList.size() << "):" << std::endl;
	for(auto &fact : factList){
		ss << "  " << fact.toString() << std::endl;
	}
	return ss.str();
}

std::string Facts::domainTostring() {
	std::stringstream ss;
	ss << "Domain(" << domain.size() << "):" << std::endl;
	for(auto &string : domain){
		ss << string << std::endl;
	}
	return ss.str();
}

void Facts::addFact(Lexer &lexer) {
	factList.emplace_back(Fact(lexer));
	if(lexer.checkNextType(Token::ID))
		addFact(lexer);
}

void Facts::buildDomain() {
	for (auto &fact : factList){
		auto temp = fact.getStrings();
		for (auto &string: temp){
			domain.push_back(string.toString());
		}
	}
	std::sort(domain.begin(),domain.end());
	auto it = std::unique(domain.begin(),domain.end());
	domain.resize(std::distance(domain.begin(),it));
}
