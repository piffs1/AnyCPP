#ifndef NOFLY_H
#define NOFLY_H

#include "IFlyable.h"

class NoFly : public IFlyable
{
    public:
        NoFly();
        virtual void Fly() override;
        virtual ~NoFly();

    protected:

    private:
};

#endif // NOFLY_H
