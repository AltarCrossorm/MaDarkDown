#pragma once

#include "block.hpp"

class Header: public Block
{
	unsigned int size;
public:
	Header(int headerSize, char* content) : Block{Type::HEADER,content,R"(<h{}>{}</h{}>)"}, size(headerSize) {}
	
	virtual std::string formatObject(void) override {
		std::string format = this->formatChilds();
		return std::vformat(this->_formatter,std::make_format_args(this->size,format,this->size));
	}
};
