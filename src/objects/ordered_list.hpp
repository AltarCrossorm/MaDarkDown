#pragma once

#include "block.hpp"

#include <vector>

class OrderedList: public Block
{
        std::vector<object*> _points;
        std::string formatPoint = R"(<li>{}</li>)";
        OrderedList(std::vector<object*> points)
        : Block{Type::ORDERED_LIST,nullptr,R"(<ol>{}</ol>)"},
          _points(points) {}

        virtual std::string formatObject(void) override
        {
                std::string finalFormat,
                            tempPoint;
                for(auto point : this->_points){
                        tempPoint = point->formatChilds();
                        finalFormat += std::vformat('\n' + this->formatPoint,std::make_format_args(tempPoint));
                }

                return std::vformat('\n' + finalFormat,std::make_format_args(finalFormat));
        }
                 
};
