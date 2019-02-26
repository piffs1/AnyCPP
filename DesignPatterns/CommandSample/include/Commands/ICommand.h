#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <iostream>

class ICommand
{
    public:
        ICommand();
        virtual void Execute() = 0;
        virtual void Undo() = 0;
        virtual std::string Identify() = 0;
        virtual ~ICommand();

    protected:

    private:
};

#endif // ICOMMAND_H
