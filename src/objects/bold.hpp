#pragma once

#include "inline.hpp"

class Bold: public Inline
{
public:
        Bold(char* text)
        : Inline(Type::LINK,text,R"(<b>{}</b>)")
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
