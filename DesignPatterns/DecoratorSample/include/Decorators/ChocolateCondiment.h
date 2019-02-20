#ifndef CHOCOLATECONDIMENT_H
#define CHOCOLATECONDIMENT_H
#include "CondimentsDecoratorBase.h"

class ChocolateCondiment : public CondimentsDecoratorBase
{
    public:
        //ChocolateCondiment();
        ChocolateCondiment(BeverageBase *beverage);
        virtual double GetCost() override;
        virtual ~ChocolateCondiment();

    protected:

    private:
        BeverageBase *_beverage;
};

#endif // CHOCOLATECONDIMENT_H
