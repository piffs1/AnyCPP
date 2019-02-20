#include "DragonFactory.h"

DragonFactory::DragonFactory()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //ctor
}

DragonFactory::~DragonFactory()
{

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

Movement* DragonFactory::CreateMovement()
{
    return new FlyMovement();
}

Weapon* DragonFactory::CreateWeapon()
{
    return new Fire();
}

