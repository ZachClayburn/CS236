//
// Created by zach on 9/20/17.
//

#ifndef CS236_LAB_INPUTCHARS_H
#define CS236_LAB_INPUTCHARS_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * A Class containing the contents of an input file
 *
 * This class exists to allow the program to quickly parse through the contents of a given input file by reading in
 * the file in its entirety and storing it in memory.
 */
class InputChars {

public:
	/**
	 * Constructs an InputChars object.
	 *
	 * Takes the given filename, opens the file and reads in the contents, then dispenses the contents of the file
	 * @param fileName the name of the file to be read in
	 * @returns an InputChars object
	 */
	InputChars(const char* fileName);

	/**
	 * Get the next character.
	 *
	 * Returns the next char and advances to the next char
	 * @return The next character in the file contents
	 */
	char getNext();

	/**
	 * Peek at the next character.
	 *
	 * Like getNext, but doesn't advance the pointer to the next char
	 * @return The next character in the file contents
	 */
	char peekNext();

	/**
	 * Get the line number the current character is from.
	 *
	 * Returns the line number that the InputChars is currently on. Note that, because the current line is iterated
	 * after getNext is called, you should call getCurLine before calling getNext
	 * @return The line that InputChars is currently on
	 */
	int getLine() const;

	/**
	 * Get current position in the file.
	 *
	 * Returns the index of the next char to be passed out by Input chars, starting at 0. So, if you have yet to call
	 * getNext, it will return 0, after calling getNext it will return 1, etc
	 * @return The index of the current position in the file
	 */
	unsigned long getPosition() const;
	
	/**
	 * Move to a given position in a file.
	 *
	 * Relocate InputChars to a given position in a file, with 0 corresponding to the beginning
	 * @param index the index to move to
	 */
	void moveToPosition(int index);

	/**
	 * Test if InputChars is at the end of file.
	 *
	 * @return True if at EOF, false otherwise
	 */
	bool isEOF();

private:

	/**
	 * The contents of the file.
	 */
	std::string chars;

	/**
	 * The current position.
	 */
	unsigned long curPos;

	/**
	 * The Current Line number.
	 */
	unsigned int curLine;
};


#endif //CS236_LAB_INPUTCHARS_H
