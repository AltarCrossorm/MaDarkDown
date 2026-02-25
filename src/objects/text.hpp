#pragma once

#include "inline.hpp"

class Text: public Inline
{
public:
        Text(char text)
        : Inline(Type::LINK,&text,"")
          {}

        virtual std::string formatObject(void) override
        {
                return this->_rawContent;
        }
};
