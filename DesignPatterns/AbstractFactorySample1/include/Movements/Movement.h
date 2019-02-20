#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>

class Movement
{
    public:
        Movement();
        virtual void Move() = 0;
        virtual ~Movement();

    protected:

    private:
};

#endif // MOVEMENT_H
