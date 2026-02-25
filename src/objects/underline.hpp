#pragma once

#include "inline.hpp"

class Underline: public Inline
{
public:
        Underline(char* text)
        : Inline(Type::LINK,text,R"(<u>{}</u>)")
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
