//
// Created by zach on 9/18/17.
//

#include "Lexer.h"

Lexer::Lexer(InputChars& input) {

	while(!input.isEOF()){
		unsigned long pos = input.getPosition();
		int line = input.getLine();
		char next = input.getNext();


		while(isspace(next)){
			pos = input.getPosition();
			line = input.getLine();
			next = input.getNext();
			if(input.isEOF()){
				tokens.emplace_back(Token(line,std::to_string(next),Token::ENDOFFILE));
				//add the function that will clean up the ID that are keywords
				return;
			}
		}

		switch (next){
			case ',' :  tokens.emplace_back(Token(line,std::to_string(next),Token::COMMA));         break;
			case '.' :  tokens.emplace_back(Token(line,std::to_string(next),Token::PERIOD));        break;
			case '?' :  tokens.emplace_back(Token(line,std::to_string(next),Token::Q_MARK));        break;
			case '(' :  tokens.emplace_back(Token(line,std::to_string(next),Token::LEFT_PAREN));    break;
			case ')' :  tokens.emplace_back(Token(line,std::to_string(next),Token::RIGHT_PAREN));   break;
			case ':' :  addColon(input,line);                                                       break;
			case '*' :  tokens.emplace_back(Token(line,std::to_string(next),Token::MULTIPLY));      break;
			case '+' :  tokens.emplace_back(Token(line,std::to_string(next),Token::ADD));           break;
			case '\'':  addString(input,line);                                                      break;
			case '#' :  addComment(input,line);                                                     break;
			default  :  addID(input,next,line);                                                     break;
		}
	}
}

void Lexer::addColon(InputChars &input, int currentLine) {

	if(input.peekNext() == '-'){
		tokens.emplace_back(Token(currentLine,":-",Token::COLON_DASH));
	} else{
		tokens.emplace_back(Token(currentLine,":",Token::COLON));
	}
}

void Lexer::addString(InputChars &input, int currentLine) {

	std::string string = "'";
	char next = input.getNext();
	if(next == '\''){
		string += "'";
		tokens.emplace_back(Token(currentLine,string,Token::STRING));
		return;
	}
	while(!input.isEOF()){
		next = input.getNext();
		if(next == '\''){
			if(input.peekNext() == '\''){
				next = input.getNext();
				string += next;
			} else{
				string += next;
				tokens.emplace_back(Token(currentLine,string,Token::STRING));
				return;
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
		if(!multiLine && next == '/n'){
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
		tokens.emplace_back(Token(currentLine,std::to_string(next),Token::UNDEFINED));
		return;
	}
	std::string string = std::to_string(next);
	while(!input.isEOF()){
		if(isalnum(input.peekNext())){
			string += input.getNext();
		}else if(isspace(input.peekNext())){
			next = input.getNext();
			tokens.emplace_back(Token(currentLine, string,Token::ID));
			return;
		}else{
			tokens.emplace_back(Token(currentLine,string,Token::ID));
			tokens.emplace_back((Token(input.getLine(),std::to_string(input.getNext()),Token::UNDEFINED)));
			return;
		}
	}
}
