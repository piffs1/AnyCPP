#ifndef CONDIMENTSDECORATORBASE_H
#define CONDIMENTSDECORATORBASE_H
#include "BeverageBase.h"

class CondimentsDecoratorBase :  public BeverageBase
{
    public:
        CondimentsDecoratorBase();
        virtual ~CondimentsDecoratorBase();
    protected:
        //double _cost;
    private:


};

#endif // CONDIMENTSDECORATORBASE_H
