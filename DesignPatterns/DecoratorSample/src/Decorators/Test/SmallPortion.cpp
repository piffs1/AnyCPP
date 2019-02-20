#include "SmallPortion.h"
/*
SmallPortion::SmallPortion()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _cost = 30;
    //ctor
}*/

SmallPortion::SmallPortion(BeverageBase *beverage)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _beverage = beverage;
    _cost = 30;
    _description = _beverage->GetDiscription() + " + small portion";
    //ctor
}

SmallPortion::~SmallPortion()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_beverage!=nullptr)
        delete _beverage;
    //dtor
}

double SmallPortion::GetCost()
{
    return _beverage->GetCost() + _cost;
}
