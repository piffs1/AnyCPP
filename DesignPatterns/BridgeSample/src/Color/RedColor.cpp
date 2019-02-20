#include "RedColor.h"

RedColor::RedColor()
{
    _rgb.R = 255;
    _rgb.G = 0;
    _rgb.B = 0;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

RedColor::~RedColor()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void RedColor::Paint()
{
    std::cout << "Red color" << std::endl;
}
