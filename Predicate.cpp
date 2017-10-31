//
// Created by zach on 10/9/17.
//

#include "Predicate.h"

Predicate::Predicate(Lexer &lexer) :
		predicateID(lexer){
	lexer.getNext(Token::LEFT_PAREN);
	addParameter(lexer);
	lexer.getNext(Token::RIGHT_PAREN);
}

/*
Predicate::~Predicate() {
	for (auto &parameter : parameterList)
		delete parameter;

}
*/

std::string Predicate::toString() {
	std::stringstream ss;
	ss << predicateID.toString() << '(';
	for(int i = 0; i < parameterList.size(); i++){
		ss << parameterList.at(i)->toString();
		if(i < parameterList.size()-1){
			ss << ',';
		}
	}

	ss << ')';

	return ss.str();
}

void Predicate::addParameter(Lexer& lexer) {
	if(lexer.checkNextType(Token::ID))
		parameterList.push_back(new ID(lexer));
	else if(lexer.checkNextType(Token::STRING))
		parameterList.push_back(new String(lexer));
	else
		parameterList.push_back(new Expression(lexer));

	if(lexer.checkNextType(Token::COMMA)){
		lexer.getNext(Token::COMMA);
		addParameter(lexer);
	}
}

std::string Predicate::getIDString() {
	return predicateID.toString();
}

std::vector<SelectionKey *> Predicate::getSelectionKeys() {
	std::vector<SelectionKey *> keys;
	int col = 0;
	std::map<std::string,int> IDs;

	for(auto &param : parameterList){
		switch(param->getType()){
			case Token::STRING: {
				keys.push_back(new ColumnValueKey(col, param->toString()));
			}
				break;
			case Token::ID: {
				std::pair<std::string, int> tempPair(param->toString(), col);
				auto state = IDs.insert(tempPair);
				if (!state.second)
					keys.push_back(new ColumnColumnKey(state.first->second, col));
			}
				break;
			default:
				std::cout << "There was an Error in Predicate::getSelectionKeys()!\n";
				break;
		}
		col++;
	}

	return keys;
}

std::vector<int> Predicate::getColumnsToKeep() {
	std::vector<int> columnsToKeep;
	int col = 0;
	std::map<std::string,int> IDs;

	for(auto &param : parameterList){
		if(param->getType() == Token::ID){
			std::pair<std::string, int> tempPair(param->toString(), col);
			auto state = IDs.insert(tempPair);
			if (state.second)
				columnsToKeep.push_back(col);
		}
		col++;
	}
	return columnsToKeep;
}
