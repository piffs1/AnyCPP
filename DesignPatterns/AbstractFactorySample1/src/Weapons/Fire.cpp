#include "Fire.h"

Fire::Fire()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    type = "Fire";
    //ctor
}

Fire::~Fire()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Fire::Hit()
{
    std::cout << "Fire hit!" << std::endl;
}
