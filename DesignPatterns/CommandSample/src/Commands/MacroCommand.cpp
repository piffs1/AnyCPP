#include "MacroCommand.h"

MacroCommand::MacroCommand(std::vector <ICommand*> &commands)
{

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _innerCommands = commands;
    //ctor
}

MacroCommand::~MacroCommand()
{
    for(auto it = _innerCommands.begin(); it!=_innerCommands.end(); ++it)
    {
        delete (*it);
    }
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void MacroCommand::Execute()
{
    for(auto it = _innerCommands.begin(); it!=_innerCommands.end(); ++it)
    {
        (*it)->Execute();
    }
}

void MacroCommand::Undo()
{
    for(auto it = _innerCommands.begin(); it!=_innerCommands.end(); ++it)
    {
        (*it)->Undo();
    }
}

std::string MacroCommand::Identify()
{
    std::string result = "MacroCommand(";
    for(auto it = _innerCommands.begin(); it!=_innerCommands.end(); ++it)
        {result+=(*it)->Identify(); result+=",";}
    result[result.size()-1] = ')';
    return result;
}
