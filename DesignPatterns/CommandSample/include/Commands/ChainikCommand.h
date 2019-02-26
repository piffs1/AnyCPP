#ifndef CHAINIKCOMMAND_H
#define CHAINIKCOMMAND_H

#include "ICommand.h"
#include "Chainik.h"

class ChainikCommand : public ICommand
{
    public:
        ChainikCommand(Chainik* chainik);
        virtual void Execute() override;
        virtual void Undo() override;
        virtual std::string Identify() override;
        virtual ~ChainikCommand();

    protected:

    private:
        Chainik* _chainik;
};

#endif // CHAINIKCOMMAND_H
