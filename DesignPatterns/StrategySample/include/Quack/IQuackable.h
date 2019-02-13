#ifndef IQUACKABLE_H
#define IQUACKABLE_H

#include <iostream>


class IQuackable
{
    public:
        IQuackable();
        virtual void Quack() = 0;
        virtual ~IQuackable();

    protected:

    private:
};

#endif // IQUACKABLE_H
