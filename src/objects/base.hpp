#pragma once

#include <vector>
#include <utility>
#include <type_traits>
#include <iostream>
#include <format>

enum class Type {
	// block
	HEADER,
	SUBTEXT,
	CODEBLOCK,
	NOTE,
	COLORED_NOTE,
	TABLE,
	ORDERED_LIST,
	UNORDERED_LIST,
	CHECKBOX,

	// inline
	LINK,
	IMAGE,
	BOLD,
	ITALIC,
	CODE,
	UNDERLINE,
	SPOILER,
	STRIKETHROUGH,
	SUPERSCRIPT,
	SUBSCRIPT,

	// Default
	TEXT,
};

class object
{
protected:
	std::string _rawContent;
	Type _typeObject;
	std::vector<object*> *_childObjects;
	const std::string _formatter;
public:
	object(Type type, std::string content, const std::string formatter) : _rawContent(content), _typeObject(type), _formatter(formatter)
	{
		if (_typeObject != Type::TEXT) // base object
			_childObjects = new std::vector<object*>;
		else
			_childObjects = nullptr;
	}

	void addChild(object* child) { _childObjects->push_back(child); }

	std::vector<object*>* getChilds(void) { return _childObjects; }

	std::string formatChilds(void)
	{
		std::string result = "";
		if (_childObjects) {
			// Syntaxe correcte pour déréférencer le membre
			for (object *child : *_childObjects) {
				result += child->formatObject();
			}
		}
		return result;
	}

	virtual std::string formatObject(void) = 0;

	std::ostream& operator<<(std::ostream &os)
	{
		return os << "<Object value : " << std::to_underlying(this->_typeObject) << " content = \"" << this->_rawContent << "\">";
	}
};
