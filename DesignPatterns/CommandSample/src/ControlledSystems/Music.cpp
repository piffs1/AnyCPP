#include "Music.h"

Music::Music()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

Music::~Music()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Music::TurnOff()
{
    std::cout << "Music Off" << std::endl;
    _state = State::OFF1;
}

void Music::TurnOn()
{
    std::cout << "Music On" << std::endl;
    _state = State::ON;
}
