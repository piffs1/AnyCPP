#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
    public:
        Weapon();
        virtual void Hit() = 0;
        virtual ~Weapon();

    protected:
        std::string type;
    private:
};

#endif // WEAPON_H
