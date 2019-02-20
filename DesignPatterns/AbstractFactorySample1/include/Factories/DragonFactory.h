#ifndef DRAGONFACTORY_H
#define DRAGONFACTORY_H

#include "HeroFactory.h"
#include "FlyMovement.h"
#include "Fire.h"

class DragonFactory : public HeroFactory
{
    public:
        DragonFactory();
        virtual Movement* CreateMovement() override;
        virtual Weapon* CreateWeapon() override;
        virtual ~DragonFactory();

    protected:

    private:
};

#endif // DRAGONFACTORY_H
