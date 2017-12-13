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

bool Rule::morePredicates() {
	return curPred < predicateList.size();
}

Predicate *Rule::getPredicate() {
	Predicate* rValue = &(predicateList.at(curPred));
	curPred++;
	return rValue;
}

std::string Rule::getHeadID() {
	return head.getID();
}

std::vector<int> Rule::getColumnsToKeep(std::vector<std::string> headerCols) {
	return head.getColumnsToKeep(headerCols);
}

std::vector<ColumnNamePair> Rule::getRenames() {
	std::vector<std::string> headNames = head.getIdStrings();
	std::vector<ColumnNamePair> renames(headNames.size(),ColumnNamePair());
	for(size_t i = 0; i < renames.size(); i++)
		renames.at(i) = ColumnNamePair((int)i,headNames.at(i));
	return renames;
}

void Rule::reset() {
	curPred = 0;
}

std::vector<std::string> Rule::getPredicateIDs() {
	std::vector<std::string> predicateIDs(predicateList.size(),"");
	for(int i = 0; i < predicateIDs.size(); i++){
		predicateIDs.at(i) = predicateList.at(i).getIDString();
	}
	return predicateIDs;
}
