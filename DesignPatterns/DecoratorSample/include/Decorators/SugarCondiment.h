#ifndef SUGARCONDIMENT_H
#define SUGARCONDIMENT_H
#include "CondimentsDecoratorBase.h"

class SugarCondiment : public CondimentsDecoratorBase
{
    public:
        //SugarCondiment();
        SugarCondiment(BeverageBase *beverage);
        virtual double GetCost() override;
        virtual ~SugarCondiment();

    protected:

    private:

        BeverageBase *_beverage;
};

#endif // SUGARCONDIMENT_H
