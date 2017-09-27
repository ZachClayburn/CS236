//
// Created by zach on 9/18/17.
//

#include "Lexer.h"

Lexer::Lexer(InputChars& input) {
	int line = 0;
	char next = ' ';
	while(!input.isEOF()){
		line = input.getLine();
		next = input.getNext();


		while(isspace(next)){
			if(input.isEOF()){
				tokens.emplace_back(Token(input.getLine(), "", Token::ENDOFFILE));
				cleanup();
				return;
			}
			line = input.getLine();
			next = input.getNext();
		}

		switch (next){
			case ',' :  tokens.emplace_back(Token(line,std::string(1,next),Token::COMMA));          break;
			case '.' :  tokens.emplace_back(Token(line,std::string(1,next),Token::PERIOD));         break;
			case '?' :  tokens.emplace_back(Token(line,std::string(1,next),Token::Q_MARK));         break;
			case '(' :  tokens.emplace_back(Token(line,std::string(1,next),Token::LEFT_PAREN));     break;
			case ')' :  tokens.emplace_back(Token(line,std::string(1,next),Token::RIGHT_PAREN));    break;
			case ':' :  addColon(input,line);                                                       break;
			case '*' :  tokens.emplace_back(Token(line,std::string(1,next),Token::MULTIPLY));       break;
			case '+' :  tokens.emplace_back(Token(line,std::string(1,next),Token::ADD));            break;
			case '\'':  addString(input,line);                                                      break;
			case '#' :  addComment(input,line);                                                     break;
			default  :  addID(input,next,line);                                                     break;
		}
	}
	tokens.emplace_back(Token(input.getLine(),"", Token::ENDOFFILE));
	cleanup();
}

void Lexer::printTokens() {
	for(auto &token : tokens){
		std::cout << token.toString() << std::endl;
	}
	std::cout << "Total Tokens = " << tokens.size();

}

void Lexer::addColon(InputChars &input, int currentLine) {

	if(input.peekNext() == '-'){
		char next = input.getNext();
		tokens.emplace_back(Token(currentLine,":-",Token::COLON_DASH));
	} else{
		tokens.emplace_back(Token(currentLine,":",Token::COLON));
	}
}

void Lexer::addString(InputChars &input, int currentLine) {

	std::string string = "'";
	char next;
	if(input.peekNext() == '\''){
		string += input.getNext();
		tokens.emplace_back(Token(currentLine,string,Token::STRING));
		return;
	}
	while(!input.isEOF()){
		next = input.getNext();
		if(next == '\''){
			if(input.peekNext() != '\''){
				for(int i = 1; i < string.size(); i++){
					if(string.at((unsigned long)i) == '\'' && string.at((unsigned long)i - 1) == '\''){
						string.erase((unsigned long)i,1);
					}
				}
				string += next;
				tokens.emplace_back(Token(currentLine,string,Token::STRING));
				return;
			} else{
				string += next;
				next = input.getNext();
				string += next;
			};
		} else{
			string += next;
		}
	}
	tokens.emplace_back(Token(currentLine,string,Token::UNDEFINED));
}

void Lexer::addComment(InputChars &input, int currentLine) {
	std::string string = "#";
	bool multiLine = input.peekNext() == '|';
	while(!input.isEOF()){
		char next = input.getNext();
		if(!multiLine && next == '\n'){
			tokens.emplace_back(Token(currentLine,string,Token::COMMENT));
			return;
		}
		string += next;
		if(multiLine && next == '|'){
			if(input.peekNext() == '#'){
				string += input.getNext();
				tokens.emplace_back(Token(currentLine,string,Token::COMMENT));
				return;
			}
		}
	}
	if(multiLine)
		tokens.emplace_back(Token(currentLine,string,Token::UNDEFINED));
	else
		tokens.emplace_back(Token(currentLine,string,Token::COMMENT));
}

void Lexer::addID(InputChars &input, char next, int currentLine) {
	if(!isalpha(next)){
		tokens.emplace_back(Token(currentLine,std::string(1,next),Token::UNDEFINED));
		return;
	}
	std::string string = std::string(1,next);
	while(!input.isEOF()){
		if(isalnum(input.peekNext())){
			string += input.getNext();
		}else{
			tokens.emplace_back(Token(currentLine,string,Token::ID));
			return;
		}
	}
}

void Lexer::cleanup() {
	for (auto &token : tokens) {
		if(token.type == Token::ID){
			if(token.string == "Schemes"){
				token.setType(Token::SCHEMES);
			}else if(token.string == "Facts"){
				token.setType(Token::FACTS);
			}else if(token.string == "Rules"){
				token.setType(Token::RULES);
			}else if(token.string == "Queries"){
				token.setType(Token::QUERIES);
			}
		}
	}
}
