#ifndef HERO_H
#define HERO_H

#include "HeroFactory.h"

#include <iostream>
class Hero
{
    public:
        Hero(HeroFactory *factory);
        void Run();
        void Hit();
        virtual ~Hero();

    protected:

    private:
        HeroFactory* _factory;
        Weapon* _weapon;
        Movement* _movement;
};

#endif // HERO_H
