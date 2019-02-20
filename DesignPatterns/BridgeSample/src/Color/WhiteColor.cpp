#include "WhiteColor.h"

WhiteColor::WhiteColor()
{
    _rgb.R = 255;
    _rgb.G = 255;
    _rgb.B = 255;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

WhiteColor::~WhiteColor()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void WhiteColor::Paint()
{
    std::cout << "White Color" << std::endl;
}
