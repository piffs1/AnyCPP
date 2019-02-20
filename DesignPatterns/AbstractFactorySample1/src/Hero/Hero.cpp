#include "Hero.h"

Hero::Hero(HeroFactory *factory)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _factory = factory;
    _weapon = factory->CreateWeapon();
    _movement = factory->CreateMovement();
    //ctor
}

Hero::~Hero()
{
    if(_weapon!=nullptr) ///?
        delete _weapon;
    if(_movement!=nullptr) ///?
        delete _movement;
    if(_factory!=nullptr)
        delete _factory;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    //dtor
}

void Hero::Run()
{
    _movement->Move();
}

void Hero::Hit()
{
    _weapon->Hit();
}
