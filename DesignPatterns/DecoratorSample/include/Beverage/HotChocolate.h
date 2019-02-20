#ifndef HOTCHOCOLATE_H
#define HOTCHOCOLATE_H
#include "BeverageBase.h"

class HotChocolate : public BeverageBase
{
    public:
        HotChocolate();
        virtual double GetCost() override;
        virtual ~HotChocolate();

    protected:

    private:
};

#endif // HOTCHOCOLATE_H
