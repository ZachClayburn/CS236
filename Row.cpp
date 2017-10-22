//
// Created by zach on 10/21/17.
//

#include "Row.h"

Row::Row(std::list<std::string> contentsIn) {
	contents = contentsIn;

}

size_t Row::size() {
	return contents.size();
}
