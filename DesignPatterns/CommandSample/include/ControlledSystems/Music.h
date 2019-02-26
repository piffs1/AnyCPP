#ifndef MUSIC_H
#define MUSIC_H

#include "CSBase.h"

class Music
{
    public:
        Music();
        void TurnOn();
        void TurnOff();
        State _state;
        virtual ~Music();

    protected:

    private:

};

#endif // MUSIC_H
