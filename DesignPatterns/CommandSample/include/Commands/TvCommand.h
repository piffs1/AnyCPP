#ifndef TVCOMMAND_H
#define TVCOMMAND_H

#include "ICommand.h"
#include "TV.h"

class TvCommand : public ICommand
{
    public:
        TvCommand(TV* tv);
        virtual void Execute() override;
        virtual void Undo() override;
        virtual std::string Identify() override;
        virtual ~TvCommand();

    protected:

    private:
        TV* _tv;
};

#endif // TVCOMMAND_H
