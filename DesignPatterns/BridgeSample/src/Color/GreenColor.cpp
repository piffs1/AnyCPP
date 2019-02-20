#include "GreenColor.h"

GreenColor::GreenColor()
{
    _rgb.R = 0;
    _rgb.G = 255;
    _rgb.B = 0;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

GreenColor::~GreenColor()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void GreenColor::Paint()
{
    std::cout << "Green color" << std::endl;
}
