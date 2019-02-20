#ifndef MILKCONDIMENT_H
#define MILKCONDIMENT_H
#include "CondimentsDecoratorBase.h"

class MilkCondiment : public CondimentsDecoratorBase
{
    public:
        //MilkCondiment();
        MilkCondiment(BeverageBase *beverage);
        virtual double GetCost() override;
        virtual ~MilkCondiment();

    protected:

    private:
        BeverageBase *_beverage;
};

#endif // MILKCONDIMENT_H
