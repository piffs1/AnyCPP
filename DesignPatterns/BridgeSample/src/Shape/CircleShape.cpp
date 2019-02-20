#include "CircleShape.h"

CircleShape::CircleShape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

CircleShape::CircleShape(unsigned int radius)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _radius = radius;
}

CircleShape::~CircleShape()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void CircleShape::Draw()
{
    std::cout << "Drawing CircleShape ";
    _color->Paint();
}

unsigned int CircleShape::GetRadius()
{
    return _radius;
}

void CircleShape::SetRadius(unsigned int radius)
{
    _radius = radius;
}
