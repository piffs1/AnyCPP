#include "Capuccino.h"

Capuccino::Capuccino()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _description = "Capuccino coffee";
    _cost = 200;
    //ctor
}

Capuccino::~Capuccino()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

double Capuccino::GetCost()
{
    return _cost;
}
