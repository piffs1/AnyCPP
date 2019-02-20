#include "ChocolateCondiment.h"
/*
ChocolateCondiment::ChocolateCondiment()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _cost = 120;
    //ctor
}
*/
ChocolateCondiment::ChocolateCondiment(BeverageBase *beverage)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _beverage = beverage;
    _cost = 120;
    _description = _beverage->GetDiscription() + " + Chocolate";
    //ctor
}

ChocolateCondiment::~ChocolateCondiment()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_beverage!=nullptr)
        delete _beverage;
    //dtor
}

double ChocolateCondiment::GetCost()
{
    return _beverage->GetCost() + _cost; /// ?
}
