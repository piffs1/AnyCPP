#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"
#include <iostream>
class Sword : public Weapon
{
    public:
        Sword();
        virtual void Hit() override;
        virtual ~Sword();

    protected:

    private:
};

#endif // SWORD_H
