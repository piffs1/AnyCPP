#ifndef CHAINIK_H
#define CHAINIK_H

#include "CSBase.h"

class Chainik
{
    public:
        Chainik();
        void TurnOn();
        void TurnOff();
        State _state;
        virtual ~Chainik();

    protected:

    private:

};

#endif // CHAINIK_H
