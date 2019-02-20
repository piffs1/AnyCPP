#include "MilkCondiment.h"
/*
MilkCondiment::MilkCondiment()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _cost = 90;
    //ctor
}
*/
MilkCondiment::MilkCondiment(BeverageBase *beverage)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _beverage = beverage;
    _cost = 90;
    _description = _beverage->GetDiscription() + " + milk";

    //ctor
}

MilkCondiment::~MilkCondiment()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_beverage!=nullptr)
        delete _beverage;
    //dtor
}

double MilkCondiment::GetCost()
{
    return _beverage->GetCost() + _cost; /// ?
}
