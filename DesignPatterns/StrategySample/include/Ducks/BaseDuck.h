#ifndef BASEDUCK_H
#define BASEDUCK_H

#include <iostream>

#include "IFlyable.h"
#include "IQuackable.h"
#include "FlyWithWings.h"
#include "ExoticQuack.h"
#include "NoQuack.h"
#include "NoFly.h"
#include "SimpleQuack.h"
/// need help!
class BaseDuck
{
    public:
        BaseDuck();
        virtual void Drive() = 0;
        virtual void Fly();
        virtual void Quack();
        void Swim() {std::cout << "I'm Swimming" << std::endl;}
        virtual ~BaseDuck();

    protected:
        IFlyable *flyBehaviour;
        IQuackable *quackBehaviour;
    private:
};

#endif // BASEDUCK_H
