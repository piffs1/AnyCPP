#ifndef BLACKTEA_H
#define BLACKTEA_H

#include "BeverageBase.h"

class BlackTea : public BeverageBase
{
    public:
        BlackTea();
        virtual double GetCost() override;
        virtual ~BlackTea();

    protected:

    private:
};

#endif // BLACKTEA_H
