#ifndef SMALLPORTION_H
#define SMALLPORTION_H

#include "PortionsDecoratorBase.h"

class SmallPortion : public PortionsDecoratorBase
{
    public:
        //SmallPortion();
        SmallPortion(BeverageBase *beverage);
        virtual double GetCost() override;
        virtual ~SmallPortion();

    protected:

    private:
        BeverageBase *_beverage;// = nullptr;
};

#endif // SMALLPORTION_H
