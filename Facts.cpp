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
	int i = 0;
	for (const auto &it : domain) {
		ss << "  " << it;
		if(i < domain.size()-1)
			ss << std::endl;
		i++;
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
			domain.insert(string.toString());
		}
	}
}

bool Facts::moreFacts() {
	return curFact < factList.size();
}

std::string Facts::getFactScheme() {
	return factList.at(curFact).getID();
}

std::vector<std::string> Facts::getFactContents() {
	std::vector<String> contentStrings = factList.at(curFact).getStrings();
	curFact++;
	std::vector<std::string> rvalue;
	for(auto &string : contentStrings){
		rvalue.push_back(string.toString());
	}
	return rvalue;
}
