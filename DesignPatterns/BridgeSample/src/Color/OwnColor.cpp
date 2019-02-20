#include "OwnColor.h"

OwnColor::OwnColor(RGB &rgb)
{
    _rgb = rgb;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

OwnColor::OwnColor(unsigned char R, unsigned char G, unsigned char B)
{
    _rgb.R = R;
    _rgb.G = G;
    _rgb.B = B;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

OwnColor::~OwnColor()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void OwnColor::Paint()
{
    std::cout << "Color with intensity RGB(" << _rgb.R << "," << _rgb.G << "," << _rgb.B << ")" << std::endl;
}
