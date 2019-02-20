#ifndef ARBALET_H
#define ARBALET_H

#include "Weapon.h"
#include <iostream>
class Arbalet : public Weapon
{
    public:
        Arbalet();
        virtual void Hit() override;
        virtual ~Arbalet();

    protected:

    private:
};

#endif // ARBALET_H
