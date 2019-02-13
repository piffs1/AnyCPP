#include "SimpleDuck.h"

SimpleDuck::SimpleDuck()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    quackBehaviour = new SimpleQuack();
    flyBehaviour = new FlyWithWings();
    //ctor
}

SimpleDuck::~SimpleDuck()
{
    std::cout << __PRETTY_FUNCTION__ << "->";
    delete quackBehaviour;
    delete flyBehaviour;
    //dtor
}

void SimpleDuck::Drive()
{
    std::cout << "I'm simple duck !" << std::endl;
}
