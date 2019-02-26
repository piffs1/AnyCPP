#include "TV.h"

TV::TV()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //ctor
}

TV::~TV()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //dtor
}

void TV::TurnOff()
{
    std::cout << "TV Off" << std::endl;
    _state = State::OFF1;
}

void TV::TurnOn()
{
    std::cout << "TV On" << std::endl;
    _state = State::ON;
}
