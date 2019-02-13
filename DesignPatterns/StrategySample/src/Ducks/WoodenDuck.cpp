#include "WoodenDuck.h"

WoodenDuck::WoodenDuck()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    quackBehaviour = new NoQuack();
    flyBehaviour = new NoFly();
    //ctor
}

WoodenDuck::~WoodenDuck()
{
    std::cout << __PRETTY_FUNCTION__ << "->";
    delete quackBehaviour;
    delete flyBehaviour;
    //dtor
}

void WoodenDuck::Drive()
{
    std::cout << "I'm Wooden Duck! " << std::endl;
}
