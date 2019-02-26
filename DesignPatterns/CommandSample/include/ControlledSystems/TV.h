#ifndef TV_H
#define TV_H

#include "CSBase.h"

class TV
{
    public:
        TV();
        void TurnOn();
        void TurnOff();
        State _state;
        virtual ~TV();

    protected:

    private:

};

#endif // TV_H
