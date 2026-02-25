#pragma once

#include "block.hpp"

class Subtext: public Block
{
public:
        Subtext(char* content): Block{Type::SUBTEXT,content,R"(<subtext>{}</subtext>)"} {}

        virtual std::string formatObject(void) override 
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
