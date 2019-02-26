#ifndef MUSICCOMMAND_H
#define MUSICCOMMAND_H

#include "ICommand.h"
#include "Music.h"

class MusicCommand : public ICommand
{
    public:
        MusicCommand(Music* music);
        virtual void Execute() override;
        virtual void Undo() override;
        virtual std::string Identify() override;
        virtual ~MusicCommand();

    protected:

    private:
        Music* _music;
};

#endif // MUSICCOMMAND_H
