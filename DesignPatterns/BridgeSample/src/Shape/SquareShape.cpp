#include "SquareShape.h"

SquareShape::SquareShape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

SquareShape::~SquareShape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void SquareShape::Draw()
{
    std::cout << "Drawing SquareShape ";
    _color->Paint();
}
