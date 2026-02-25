#pragma once

#include "inline.hpp"

class Spoiler: public Inline
{
public:
        Spoiler(char* text)
        : Inline(Type::LINK,text,R"(<spoiler>{}</spoiler>)")
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
