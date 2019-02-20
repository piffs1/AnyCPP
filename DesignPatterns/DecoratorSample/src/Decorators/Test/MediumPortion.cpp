#include "MediumPortion.h"
/*
MediumPortion::MediumPortion()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _cost = 50;
    //ctor
}
*/
MediumPortion::MediumPortion(BeverageBase *beverage)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _beverage = beverage;
    _cost = 50;
    _description = _beverage->GetDiscription() + " + medium portion";
    //ctor
}

MediumPortion::~MediumPortion()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_beverage!=nullptr)
        delete _beverage;
    //dtor
}

double MediumPortion::GetCost()
{
    return _beverage->GetCost() + _cost;
}
