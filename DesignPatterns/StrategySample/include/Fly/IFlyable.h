#ifndef IFLYABLE_H
#define IFLYABLE_H

#include <iostream>

class IFlyable
{
    public:
        IFlyable();
        virtual void Fly() = 0;
        virtual ~IFlyable();

    protected:

    private:
};

#endif // IFLYABLE_H
