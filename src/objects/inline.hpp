#pragma once

#include "base.hpp"

class Inline: public object
{
public:
	Inline(Type type, char* content, const std::string format) : object{type,content,format} {}
};
