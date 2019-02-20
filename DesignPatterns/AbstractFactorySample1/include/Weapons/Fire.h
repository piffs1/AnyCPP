#ifndef FIRE_H
#define FIRE_H

#include "Weapon.h"
#include <iostream>
class Fire : public Weapon
{
    public:
        Fire();
        virtual void Hit() override;
        virtual ~Fire();

    protected:

    private:
};

#endif // FIRE_H
