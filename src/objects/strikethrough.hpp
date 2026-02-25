#pragma once

#include "inline.hpp"

class Strikethrough: public Inline
{
public:
        Strikethrough(char* text)
        : Inline(Type::LINK,text,R"(<s>{}</s>)")
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
