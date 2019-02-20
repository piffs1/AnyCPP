#ifndef PORTIONSDECORATORBASE_H
#define PORTIONSDECORATORBASE_H
#include "BeverageBase.h"

class PortionsDecoratorBase : public BeverageBase
{
    public:
        PortionsDecoratorBase();
        ///virtual double GetCost();

        virtual ~PortionsDecoratorBase();

    protected:
        double _cost;
    private:
};

#endif // PORTIONSDECORATORBASE_H
