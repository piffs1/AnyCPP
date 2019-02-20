#include "RunMovement.h"

RunMovement::RunMovement()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //ctor
}

RunMovement::~RunMovement()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void RunMovement::Move()
{
    std::cout << "Running!" << std::endl;
}
