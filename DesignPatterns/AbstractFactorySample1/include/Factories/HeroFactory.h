#ifndef HEROFACTORY_H
#define HEROFACTORY_H

#include "Movement.h"
#include "Weapon.h"

class HeroFactory
{
    public:
        HeroFactory();
        virtual Movement* CreateMovement() = 0;
        virtual Weapon* CreateWeapon() = 0;
        virtual ~HeroFactory();

    protected:

    private:
};

#endif // HEROFACTORY_H
