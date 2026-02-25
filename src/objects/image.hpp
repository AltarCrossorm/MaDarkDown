#pragma once

#include "inline.hpp"

class Image: public Inline
{
        std::string _url;
public:
        Image(char* alt, char* url)
        : Inline(Type::LINK,alt,R"(<img src="{}" alt="{}">)"),
          _url(url)
          {}

        virtual std::string formatObject(void) override
        {
                return std::vformat(this->_formatter,std::make_format_args(this->_rawContent,this->_url));
        }
};
