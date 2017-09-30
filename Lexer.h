//
// Created by zach on 9/18/17.
//

#ifndef CS236_LAB_LEXICALANALIZER_H
#define CS236_LAB_LEXICALANALIZER_H

#include <vector>
#include <cctype>
#include <iostream>
#include "Token.h"
#include "InputChars.h"

class Lexer {
public:

	/**
	 * Constructs a Lexer object.
	 *
	 * The constructor creates the Lexer object and parses through all of the input in the file named by fileName using
	 * an InputFile object, and creates tokens out of all of the contents
	 * @param fileName The name of a
	 * @returns A Lexer object
	 */
	Lexer(const char* fileName);

	/**
	 * Gets the next token.
	 *
	 * Returns the next token and advances the internal iterator to the next token
	 * @return A copy of the next token in the file
	 */
	Token getNext();

	/**
	 * Peeks at the next token.
	 *
	 * Returns the next token, but does not advance the iterator
	 * @return A copy of the next token in the file
	 */
	Token peekNext();

	/**
	 * Prints all tokens to the standard output.
	 *
	 * Iterates through the vector of Tokens and prints all of their contents.
	 */
	void printTokens();


private:

	/**
	 * The iterator of the current position in the vector of tokens
	 */
	unsigned long pos;

	/**
	 * A vector containing all of the tokens from the file
	 */
	std::vector<Token> tokens;

	/**
	 * Add COLON or COLON_DASH token.
	 *
	 * Call this when you find a colon. Will add a COLON toke, unless there is a dash after the colon, in which case it
	 * will add a COLON_DASH token. Moves the pointer in input to the correct location
	 * @param input The InputChars object the lexer is reading from
	 * @param currentLine The line that the token began on
	 */
	void addColon(InputChars& input, int currentLine);

	/**
	 * Add a STRING Token
	 *
	 * Adds STRING Token, or an UNDEFINED Token if string ends illegally. Two consecutive single quotes are counted as
	 * an apostrophe
	 * @param input The InputChars object the lexer is reading from
	 * @param currentLine The line that the token began on
	 */
	void addString(InputChars& input, int currentLine);

	/**
	 * Add a single line or multi Line COMMENT Token.
	 *
	 * Checks if comment beginning with a # is multi-line. If the comment is multi-line, but it does not end in the
	 * correct character sequence, adds an UNDEFINED Toke
	 * @param input The InputChars object the lexer is reading from
	 * @param currentLine The line that the token began on
	 */
	void addComment(InputChars& input, int currentLine);

	/**
	 * Add an ID Token.
	 *
	 * Adds any sequence of alphanumeric characters beginning with a letter as an ID token, and anything else as an
	 * UNDEFINED token. Keywords are stored as ID tokens and then are converted after the file has been fully read.
	 * @param input The InputChars object the lexer is reading from
	 * @param next The last character read from the file
	 * @param currentLine The line that the token began on
	 */
	void addID(InputChars& input, char next, int currentLine);

	/**
	 * Cleans up the keyword Tokens
	 *
	 * All keyword Tokens are all saved as ID, so this function runs through the vector of Tokens and changes all of the
	 * ID tokens that have keywords as their strings
	 */
	void cleanup();

};


#endif //CS236_LAB_LEXICALANALIZER_H
