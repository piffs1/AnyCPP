#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyable.h"

class FlyWithWings : public IFlyable
{
    public:
        FlyWithWings();
        virtual void Fly() override;
        virtual ~FlyWithWings();

    protected:

    private:
};

#endif // FLYWITHWINGS_H
