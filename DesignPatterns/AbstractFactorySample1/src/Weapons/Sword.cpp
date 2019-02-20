#include "Sword.h"

Sword::Sword()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::string type = "Sword";
    //ctor
}

Sword::~Sword()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Sword::Hit()
{
    std::cout << "Sword hit! " << std::endl;
}
