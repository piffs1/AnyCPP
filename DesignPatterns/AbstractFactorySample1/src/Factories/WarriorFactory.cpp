#include "WarriorFactory.h"

WarriorFactory::WarriorFactory()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

WarriorFactory::~WarriorFactory()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

Movement* WarriorFactory::CreateMovement()
{
    return new RunMovement();
}

Weapon* WarriorFactory::CreateWeapon()
{
    return new Sword();
}
