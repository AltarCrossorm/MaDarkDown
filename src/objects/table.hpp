#pragma once

#include "block.hpp"

enum class RowFacing
{
        NONE,
        LEFT,
        CENTER,
        RIGHT
};

struct Cell
{
        char* content;
        RowFacing direction;
};

using row = std::vector<Cell>;
using head = row;
using matrix = std::vector<row>;

class Table : public Block
{
        head _header;
        std::string headerRow = R"(<th {}>{}</th>)";

        matrix _content;
        std::string matrixRow = R"(<td {}>{}</td>)";

        std::string internalRow = R"(<tr>{}</tr>)";
public:
        Table(head header, matrix content)
        : Block{Type::TABLE,nullptr,R"(<table>{}</table>)"},
           _header(header), _content(content) {}

        virtual std::string formatObject(void) override
        {
                std::string format = "",
                            side,
                            data = "",
                            childsFormat,
                            returnal;
                // Header format
                for (Cell c: this->_header)
                {
                        childsFormat = this->formatChilds();
                        switch (c.direction)
                        {
                        case RowFacing::NONE:
                                side = "";
                                break;
                        case RowFacing::LEFT:
                                side = "left";
                                break;
                        case RowFacing::CENTER:
                                side = "center";
                                break;
                        case RowFacing::RIGHT:
                                side = "right";
                                break;
                        }
                        data += std::vformat(headerRow,std::make_format_args(side,childsFormat));
                }
                format += std::vformat(internalRow,std::make_format_args(data));

                // Data format
                for (row r: this->_content) {
                        data = ""; // Resets the contens of data
                        for (Cell c: r)
                        {
                                childsFormat = this->formatChilds();
                                switch (c.direction)
                                {
                                case RowFacing::NONE:
                                        side = "";
                                        break;
                                case RowFacing::LEFT:
                                        side = "left";
                                        break;
                                case RowFacing::CENTER:
                                        side = "center";
                                        break;
                                case RowFacing::RIGHT:
                                        side = "right";
                                        break;
                                }
                                data += std::vformat(headerRow,std::make_format_args(side,childsFormat));
                        }
                        format += std::vformat(internalRow,std::make_format_args(data));
                }

                return std::vformat(this->_formatter,std::make_format_args(format));
        }
};
