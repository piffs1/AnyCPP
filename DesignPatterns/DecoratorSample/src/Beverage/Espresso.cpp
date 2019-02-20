#include "Espresso.h"

Espresso::Espresso()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
    _description = "Espresso";
    _cost = 150;
}

Espresso::~Espresso()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

double Espresso::GetCost()
{
    return _cost;
}
