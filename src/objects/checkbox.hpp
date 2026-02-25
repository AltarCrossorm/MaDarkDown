#pragma once

#include "block.hpp"

class Checkbox: public Block 
{
        bool isChecked;
        Checkbox(char* content, bool checked)
        : Block{Type::CHECKBOX,content,R"(<input type="checkbox" id="id_{}" {}/><label for="id_{}">{}</label>)"},
          isChecked(checked)
          {}

        virtual std::string formatObject(void) override
        {
                void* id = static_cast<void*>(this);
                std::string checked = this->isChecked ? "checked" : "";
                std::string format = this->formatChilds();
                return std::vformat(this->_formatter,std::make_format_args(id,checked,id,format));
        }
};
