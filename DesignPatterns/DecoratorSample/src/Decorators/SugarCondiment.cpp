#include "SugarCondiment.h"
/*
SugarCondiment::SugarCondiment()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _cost = 70;
    //ctor
}
*/
SugarCondiment::SugarCondiment(BeverageBase *beverage)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _beverage = beverage;
    _cost = 70;
    _description = _beverage->GetDiscription() + " + Sugar";
    //ctor
}

SugarCondiment::~SugarCondiment()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_beverage!=nullptr)
        delete _beverage;
    //dtor
}

double SugarCondiment::GetCost()
{
    return _beverage->GetCost() + _cost; /// ?
}
