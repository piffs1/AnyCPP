#ifndef WOODENDUCK_H
#define WOODENDUCK_H

#include "BaseDuck.h"

class WoodenDuck : public BaseDuck
{
    public:
        WoodenDuck();
        virtual void Drive() override;
        // Fly();
        // Quack();
        virtual ~WoodenDuck();

    protected:

    private:
};

#endif // WOODENDUCK_H
