#pragma once

#include "block.hpp"
#include <map>

enum class AvailableLangs {
        C,
        CPP,
        JAVA,
        RUST,
        // Lets start w/ this
};

std::map<std::string,AvailableLangs> StringLangs = {
        {"c",AvailableLangs::C},
        {"cpp",AvailableLangs::CPP},
        {"java",AvailableLangs::JAVA},
        {"rust",AvailableLangs::RUST}
};

class Codeblock : public Block
{
        std::string lang;

public:
        Codeblock(std::string language, char* content): Block{Type::CODEBLOCK, content,R"(<pre><codeblock lang="{}">{}</codeblock></pre>)"}, lang(language) {}

        virtual std::string formatObject(void) override
        {
                std::string format = this->formatChilds();
                std::string language = StringLangs.contains(lang) ? lang : "";
                return std::vformat(this->_formatter, std::make_format_args(language,format));
        }
};
