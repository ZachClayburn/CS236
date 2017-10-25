//
// Created by zach on 10/21/17.
//

#ifndef CS236_LAB_SELECTIONKEY_H
#define CS236_LAB_SELECTIONKEY_H

#include <string>
#include "Row.h"

class SelectionKey {

public:

	virtual bool checkMatch(const Row &row) const = 0;

};


#endif //CS236_LAB_SELECTIONKEY_H
