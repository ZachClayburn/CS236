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

void Rules::addRule(Lexer &lexer) {
	if(lexer.checkNextType(Token::ID)){
		rulesList.emplace_back(Rule(lexer));
		lexer.getNext(Token::PERIOD);
		addRule(lexer);
	}

}

Rule *Rules::at(int pos) {
	return &(rulesList.at(pos));
}

size_t Rules::size() {
	return rulesList.size();
}

Graph Rules::getCallGraph() {
	Graph callGraph((int)rulesList.size());

	std::map<std::string,std::list<int>> nameMap;

	for(int i = 0; i < rulesList.size(); i++){
		std::string currentHeadID = rulesList.at(i).getHeadID();
		nameMap.insert(std::pair<std::string,std::list<int>>(currentHeadID,std::list<int>()));
		nameMap.at(currentHeadID).push_back(i);
	}

	for(int i = 0; i < rulesList.size(); i++){
		std::vector<std::string> predicateIDs = rulesList.at(i).getPredicateIDs();
		for(int j = 0; j < predicateIDs.size(); j++){
			auto it = nameMap.find(predicateIDs.at(j));
			if(it != nameMap.end()){
				for(auto& ruleNumber : it->second){
					callGraph.addEdge(i,ruleNumber);
				}
			}
		}
	}


	return callGraph;
}
