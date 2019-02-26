#include "Light.h"

Light::Light()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _state = LightsState::OFF;
    //ctor
}

Light::~Light()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Light::TurnOff()
{
    _state = LightsState::OFF;
    PrintLight();
}

void Light::ToggleLight()
{
    switch(_state)
    {
    case LightsState::OFF:
        _state = LightsState::LOW;
        break;
    case LightsState::LOW:
        _state = LightsState::MEDIUM;
        break;
    case LightsState::MEDIUM:
        _state = LightsState::HIGH;
        break;
    case LightsState::HIGH:
        _state = LightsState::OFF;
        break;
    }
    PrintLight();
}

void Light::SetState(LightsState state)
{
    _state = state;
    PrintLight();
}

void Light::PrintLight()
{
    switch (_state)
    {
    case LightsState::OFF:
        std::cout << "Lights OFF" << std::endl;
        break;

    case LightsState::LOW:
        std::cout << "Lights LOW" << std::endl;
        break;

    case LightsState::MEDIUM:
        std::cout << "Lights MEDIUM" << std::endl;
        break;

    case LightsState::HIGH:
        std::cout << "Lights HIGH" << std::endl;
        break;
    }
}

