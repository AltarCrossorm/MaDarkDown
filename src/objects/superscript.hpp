#pragma once

#include "inline.hpp"

class Superscript: public Inline
{
public:
        Superscript(char* text)
        : Inline(Type::LINK,text,R"(<sup>{}</sup>)")
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
