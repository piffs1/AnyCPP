#ifndef WARRIORFACTORY_H
#define WARRIORFACTORY_H

#include "HeroFactory.h"
#include "RunMovement.h"
#include "Sword.h"

class WarriorFactory : public HeroFactory
{
    public:
        WarriorFactory();
        virtual Movement* CreateMovement() override;
        virtual Weapon* CreateWeapon() override;
        virtual ~WarriorFactory();

    protected:

    private:
};

#endif // WARRIORFACTORY_H
