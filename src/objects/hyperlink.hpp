#pragma once

#include "inline.hpp"

class Hyperlink: public Inline
{
        std::string _url;
public:
        Hyperlink(char* text, char* url)
        : Inline(Type::LINK,text,R"(<a href="{}">{}</a>)"),
          _url(url)
          {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(format,this->_url));
        }
};
