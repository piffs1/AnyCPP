#include "ChainikCommand.h"

ChainikCommand::ChainikCommand(Chainik* chainik)
{
    _chainik = chainik;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

ChainikCommand::~ChainikCommand()
{
    delete _chainik;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
     //dtor
}

void ChainikCommand::Execute()
{
    _chainik->TurnOn();
}

void ChainikCommand::Undo()
{
    _chainik->TurnOff();
}

std::string ChainikCommand::Identify()
{
    return "Turn on chainik";
}

