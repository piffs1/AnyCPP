#include "BaseDuck.h"

BaseDuck::BaseDuck()
{
    std::cout << __PRETTY_FUNCTION__ << "->";
    //ctor
}

BaseDuck::~BaseDuck()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void BaseDuck::Fly()
{
    flyBehaviour->Fly();
}

void BaseDuck::Quack()
{
    quackBehaviour->Quack();
}
