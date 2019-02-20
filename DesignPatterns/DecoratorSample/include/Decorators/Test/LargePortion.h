#ifndef LARGEPORTION_H
#define LARGEPORTION_H

#include "PortionsDecoratorBase.h"


class LargePortion : public PortionsDecoratorBase
{
    public:
        //LargePortion();
        LargePortion(BeverageBase *beverage);
        virtual double GetCost() override;
        virtual ~LargePortion();

    protected:

    private:
        BeverageBase *_beverage;
};

#endif // LARGEPORTION_H
