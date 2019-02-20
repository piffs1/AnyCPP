#include "YellowColor.h"

YellowColor::YellowColor()
{
    _rgb.R = 255;
    _rgb.G = 255;
    _rgb.B = 0;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

YellowColor::~YellowColor()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void YellowColor::Paint()
{
    std::cout << "Yellow Color" << std::endl;
}
