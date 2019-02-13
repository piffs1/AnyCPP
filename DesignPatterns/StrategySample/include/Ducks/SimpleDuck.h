#ifndef SIMPLEDUCK_H
#define SIMPLEDUCK_H

#include "BaseDuck.h"

class SimpleDuck : public BaseDuck
{
    public:
        SimpleDuck();
        virtual void Drive() override;
        //Fly();
        //Quack();
        virtual ~SimpleDuck();

    protected:

    private:
};

#endif // SIMPLEDUCK_H
