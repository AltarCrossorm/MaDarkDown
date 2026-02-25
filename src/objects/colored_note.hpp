#pragma once

#include "block.hpp"

enum class ColorKeyword {
	NONE = 0x888888,
	NOTE = NONE,
	WARNING = 0xFFCC00,
	ERROR = 0xCC3300,
	INFO = 0x7B3ED2,
};

class ColoredNote : public Block
{
	ColorKeyword colorKeyword;
	char* rawKeyword;
	char* colorCode;
public:
	ColoredNote(char* keyword,char* hexColor, char* content, ColorKeyword cK = ColorKeyword::NONE) 
	: Block{Type::COLORED_NOTE, content, R"(<color_note style="background-color:{};">{}</color_note>)"},
	  colorKeyword(cK), rawKeyword(keyword), colorCode(hexColor) {}

	virtual std::string formatObject(void) override
	{
		std::string format = this->formatChilds();
		std::string color = std::format(R"(#{:X}88)",std::to_underlying(colorKeyword));
		return std::vformat(this->_formatter,std::make_format_args(color,format));
	}
};
