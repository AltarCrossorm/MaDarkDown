#pragma once

#include "inline.hpp"

class Code: public Inline
{
public:
        Code(char* text)
        : Inline(Type::LINK,text,R"(<code>{}</code>)")
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
