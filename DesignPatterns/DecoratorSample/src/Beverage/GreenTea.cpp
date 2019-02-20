#include "GreenTea.h"

GreenTea::GreenTea()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _description = "Green tea";
    _cost = 125;
    //ctor
}

GreenTea::~GreenTea()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

double GreenTea::GetCost()
{
    return _cost;
}
