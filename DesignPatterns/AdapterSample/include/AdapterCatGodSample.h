#ifndef ADAPTERCATGODSAMPLE_H
#define ADAPTERCATGODSAMPLE_H

#include <iostream>

const std::string SEPARATOR = "==============================\n";

class Dog /// Adaptee class
{
public:
    Dog(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual ~Dog(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    void SpecificSpeak()
    {
        std::cout << SEPARATOR;
        std::cout << "I'm DOG GAW-GAW" << std::endl;
        std::cout << SEPARATOR;
    }
};

class Puppy /// Target class
{
public:
    Puppy(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual ~Puppy(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual void Speak()
    {
        std::cout << "==============================" << std::endl;
        std::cout << "I'm puppy tyaf-tyaf" << std::endl;
        std::cout << "==============================" << std::endl;
    }
};

class AdapterPuppy : public Puppy /// Adapter class
{
public:
    AdapterPuppy(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual ~AdapterPuppy(){std::cout << __PRETTY_FUNCTION__ << std::endl; delete _dog;}
    virtual void Speak()
    {
        _dog->SpecificSpeak();
    }
private:
    Dog *_dog = new Dog();
};


class Animal /// Client class
{
public:
    Animal(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual ~Animal(){std::cout << __PRETTY_FUNCTION__ << std::endl;if(_puppy!=nullptr) delete _puppy;}
    void Request(Puppy *puppy)
    {
        _puppy = puppy;
        _puppy->Speak();
    }
private:
    Puppy *_puppy;
};
#endif // ADAPTERCATGODSAMPLE_H
