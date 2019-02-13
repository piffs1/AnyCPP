#include "ExoticDuck.h"

ExoticDuck::ExoticDuck()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    quackBehaviour = new ExoticQuack();
    flyBehaviour = new FlyWithWings();
    //ctor
}

ExoticDuck::~ExoticDuck()
{
    std::cout << __PRETTY_FUNCTION__  << "->";
    delete quackBehaviour;
    delete flyBehaviour;
    //dtor
}

void ExoticDuck::Drive()
{
    std::cout << "I'm Exotic Duck!" << std::endl;
}
