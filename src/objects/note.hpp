#pragma once

#include "block.hpp"

class Note : public Block 
{
public:
        Note(char* content) : Block{Type::NOTE, content, R"(<note>{}</note>)"} {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter, std::make_format_args(format));
        }
};
