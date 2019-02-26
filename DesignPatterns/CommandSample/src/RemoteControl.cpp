#include "RemoteControl.h"

RemoteControl::RemoteControl()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //ctor
}

RemoteControl::~RemoteControl()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    for (auto it = _commands.begin(); it != _commands.end(); ++it)
    {
       delete it->second;
    }
    //dtor
}

void RemoteControl::SetCommandForButton(int buttonID, ICommand *cmd)
{
    _commands[buttonID] = cmd;
}

void RemoteControl::DrawMenu()
{
    std::cout << "Choose the var: \n";

    for (auto it = _commands.begin(); it != _commands.end(); ++it)
    {
        std::cout << it->first << "\t" << it->second->Identify() << std::endl;
    }
}

void RemoteControl::PushButton(int buttonID)
{
    if(_commands.find(buttonID) != _commands.end())
    {
        _commands[buttonID]->Execute();
    }
}

void RemoteControl::UndoButton(int buttonID)
{
    if(_commands.find(buttonID) != _commands.end())
    {
        _commands[buttonID]->Undo();
    }
}

