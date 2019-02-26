#include "TvCommand.h"

TvCommand::TvCommand(TV *tv)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _tv = tv;
    //ctor
}

TvCommand::~TvCommand()
{
    delete _tv;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void TvCommand::Execute()
{
    _tv->TurnOn();
}

void TvCommand::Undo()
{
    _tv->TurnOff();
}

std::string TvCommand::Identify()
{
    return "Turn on tv ";
}
