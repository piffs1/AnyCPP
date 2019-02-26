#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include <iostream>
#include <list>
#include <vector>
#include "ICommand.h"
#include "MusicCommand.h"

class MacroCommand : public ICommand
{
    public:
        MacroCommand(); /// DEFAULT CONSTRUCTOR FOR Music and TV commands
        MacroCommand(std::vector<ICommand*> &commands);
        virtual void Execute() override;
        virtual std::string Identify() override;
        virtual void Undo() override;
        virtual ~MacroCommand();

    protected:

    private:
        std::vector<ICommand*> _innerCommands;
};

#endif // MACROCOMMAND_H
