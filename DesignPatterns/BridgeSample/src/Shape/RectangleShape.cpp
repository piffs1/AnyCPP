#include "RectangleShape.h"

RectangleShape::RectangleShape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

RectangleShape::RectangleShape(int x,int y)
{
    _size.x = x;
    _size.y = y;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

RectangleShape::RectangleShape(Vector2i &v)
{
    _size = v;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

RectangleShape::~RectangleShape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void RectangleShape::Draw()
{
    std::cout << "Drawing RectangleShape ";
    _color->Paint();
}
