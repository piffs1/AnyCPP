#ifndef MEDIUMPORTION_H
#define MEDIUMPORTION_H

#include "PortionsDecoratorBase.h"

class MediumPortion : public PortionsDecoratorBase
{
    public:
        //MediumPortion();
        MediumPortion(BeverageBase *beverage);
        virtual double GetCost() override;
        virtual ~MediumPortion();

    protected:

    private:
        BeverageBase *_beverage;
};

#endif // MEDIUMPORTION_H
