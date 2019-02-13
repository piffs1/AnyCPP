#ifndef EXOTICDUCK_H
#define EXOTICDUCK_H

#include "BaseDuck.h"

class ExoticDuck : public BaseDuck
{
    public:
        ExoticDuck();
        virtual void Drive() override;
        //virtual void Fly() override;
        //virtual void Quack() override;
        virtual ~ExoticDuck();

    protected:

    private:
};

#endif // EXOTICDUCK_H
