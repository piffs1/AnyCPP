#include "BeverageBase.h"

BeverageBase::BeverageBase()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

BeverageBase::~BeverageBase()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

std::string BeverageBase::GetDiscription()
{
    return _description;
}
/*
double BeverageBase::GetCost()
{
    return _cost; ///combined between interface and abstract class.
}
*/
