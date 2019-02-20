#include "HotChocolate.h"

HotChocolate::HotChocolate()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _description = "Hot chocolate coffee";
    _cost = 250;
    //ctor
}

HotChocolate::~HotChocolate()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

double HotChocolate::GetCost()
{
    return _cost;
}
