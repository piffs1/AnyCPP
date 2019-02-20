#include "LargePortion.h"
/*
LargePortion::LargePortion()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _cost = 100;
    //ctor
}
*/
LargePortion::LargePortion(BeverageBase *beverage)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _beverage = beverage;
    _cost = 100;
    _description = _beverage->GetDiscription() + "+ large portion";
    //ctor
}

LargePortion::~LargePortion()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_beverage!=nullptr)
        delete _beverage;
    //dtor
}

double LargePortion::GetCost()
{
    return _beverage->GetCost() + _cost;
}
