#include "Arbalet.h"

Arbalet::Arbalet()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    type = "Arbalet";
    //ctor
}

Arbalet::~Arbalet()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Arbalet::Hit()
{
    std::cout << "Arbalet Hit!" << std::endl;
}
