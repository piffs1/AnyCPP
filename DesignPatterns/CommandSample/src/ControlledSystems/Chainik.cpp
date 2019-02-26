#include "Chainik.h"

Chainik::Chainik()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

Chainik::~Chainik()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Chainik::TurnOff()
{
    std::cout << "Chainik Off" << std::endl;
    _state = State::OFF1;
}

void Chainik::TurnOn()
{
    std::cout << "Chainik On" << std::endl;
    _state = State::ON;
}
