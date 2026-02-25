#pragma once

#include "base.hpp"

class Block: public object
{
public:
	virtual std::string formatObject(void) = 0;

	Block(Type type, char* content, const std::string format) : object{type,content,format} {}
};
