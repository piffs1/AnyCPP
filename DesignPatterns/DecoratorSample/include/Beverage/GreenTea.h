#ifndef GREENTEA_H
#define GREENTEA_H
#include "BeverageBase.h"

class GreenTea : public BeverageBase
{
    public:
        GreenTea();
        virtual double GetCost() override;
        virtual ~GreenTea();

    protected:

    private:
};

#endif // GREENTEA_H
