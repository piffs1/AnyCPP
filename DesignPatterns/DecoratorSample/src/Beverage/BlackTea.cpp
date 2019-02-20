#include "BlackTea.h"

BlackTea::BlackTea()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _description = "Black tea";
    _cost = 25;
    //ctor
}

BlackTea::~BlackTea()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

double BlackTea::GetCost()
{
    return _cost;
}
