#include "LightsCommand.h"

LightsCommand::LightsCommand(Light *light)
{

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _light = light;
    //ctor
}

LightsCommand::~LightsCommand()
{
    delete _light;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void LightsCommand::Execute()
{
    _states.push(_light->_state);
    _light->ToggleLight();
}

std::string LightsCommand::Identify()
{
    return "Turn on lights";
}

void LightsCommand::Undo()
{
    if(_states.size())
    {
        auto prevState = _states.top();
        _states.pop();
        _light->SetState(prevState);
    }
}
