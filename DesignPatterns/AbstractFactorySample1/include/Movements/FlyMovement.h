#ifndef FLYMOVEMENT_H
#define FLYMOVEMENT_H

#include "Movement.h"
#include <iostream>

class FlyMovement : public Movement
{
    public:
        FlyMovement();
        virtual void Move() override;
        virtual ~FlyMovement();

    protected:

    private:
};

#endif // FLYMOVEMENT_H
