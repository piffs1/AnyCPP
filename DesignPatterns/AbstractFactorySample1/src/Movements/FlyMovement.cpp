#include "FlyMovement.h"

FlyMovement::FlyMovement()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

FlyMovement::~FlyMovement()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void FlyMovement::Move()
{
    std::cout << "Flying ... " << std::endl;
}
