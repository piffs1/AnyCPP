#include "Shape.h"

Shape::Shape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

Shape::~Shape()
{
    if(_color!=nullptr)
        delete _color;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

Color* Shape::GetColor()
{
    return this->_color;
}

void Shape::SetColor(Color* color)
{
    _color = color;
}

void Shape::SetCenter(Vector2i &v)
{
    _center = v;
}

void Shape::SetCenter(int &x, int &y)
{
    _center.x = x;
    _center.y = y;
}

Vector2i Shape::GetCenter()
{
    return _center;
}
