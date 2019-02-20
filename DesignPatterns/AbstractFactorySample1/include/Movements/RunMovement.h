#ifndef RUNMOVEMENT_H
#define RUNMOVEMENT_H

#include "Movement.h"
#include <iostream>

class RunMovement : public Movement
{
    public:
        RunMovement();
        virtual void Move() override;
        virtual ~RunMovement();

    protected:

    private:
};

#endif // RUNMOVEMENT_H
