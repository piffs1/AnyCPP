#include "UpgratableDuck.h"

UpgratableDuck::UpgratableDuck()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    flyBehaviour = new FlyWithWings();
    quackBehaviour = new SimpleQuack();
    //ctor
}

UpgratableDuck::~UpgratableDuck()
{

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete flyBehaviour;
    delete quackBehaviour;
    //dtor
}
//
void UpgratableDuck::setFlyMode(IFlyable *fly)
{
    delete flyBehaviour;
    flyBehaviour = fly;
}

void UpgratableDuck::setQuackMode(IQuackable *quack)
{
    delete quackBehaviour;
    quackBehaviour = quack;
}

void UpgratableDuck::Drive()
{
    std::cout << "I'm upgratable Duck! " << std::endl;
}

void UpgratableDuck::Debug()
{
    this->Drive();
    this->Fly();
    this->Quack();
}
