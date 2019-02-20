#ifndef ADAPTERSAMPLE_H_INCLUDED
#define ADAPTERSAMPLE_H_INCLUDED

#include <iostream>


class Target
{
public:
    Target(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual void Request()
    {
        std::cout << "==============================" << std::endl;
        std::cout << "->Target Request()<-" << std::endl;
        std::cout << "==============================" << std::endl;
    }
    virtual ~Target(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};

class Adaptee
{
public:
    Adaptee(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    void SpecificRequest()
    {
        std::cout << "==============================" << std::endl;
        std::cout << "->Specific Request()<-" << std::endl;
        std::cout << "==============================" << std::endl;
    };
    virtual ~Adaptee(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
};

class Adapter : public Target
{
public:
    Adapter(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual void Request() override {_adaptee->SpecificRequest();}
    virtual ~Adapter(){std::cout << __PRETTY_FUNCTION__ << std::endl; delete _adaptee;}
private:
    Adaptee *_adaptee = new Adaptee();
};

class Client
{
public:
    Client(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    void Request(Target *target){
        _target = target;
        _target->Request();
        if(_target!=nullptr)
            delete _target;
        }
    virtual ~Client(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
private:
    Target *_target;
};

#endif // ADAPTERSAMPLE_H_INCLUDED
