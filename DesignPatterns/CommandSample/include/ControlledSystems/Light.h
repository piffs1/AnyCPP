#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

enum LightsState
{
    OFF = 0,
    LOW,
    MEDIUM,
    HIGH
};

class Light
{
    public:
        Light();
        void TurnOff();
        void ToggleLight();
        void SetState(LightsState state);
        virtual ~Light();
        LightsState _state;
    protected:

    private:
        void PrintLight();
};

#endif // LIGHT_H
