#include "MusicCommand.h"

MusicCommand::MusicCommand(Music* music)
{

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _music = music;
    //ctor
}

MusicCommand::~MusicCommand()
{
    delete _music;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void MusicCommand::Execute()
{
    _music->TurnOn();
}

void MusicCommand::Undo()
{
    _music->TurnOff();
}

std::string MusicCommand::Identify()
{
    return "Turn on music ";
}
