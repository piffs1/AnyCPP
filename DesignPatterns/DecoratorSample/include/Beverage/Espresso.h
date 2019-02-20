#ifndef ESPRESSO_H
#define ESPRESSO_H
#include "BeverageBase.h"

class Espresso : public BeverageBase
{
    public:
        Espresso();
        virtual double GetCost() override;
        virtual ~Espresso();

    protected:

    private:
};

#endif // ESPRESSO_H
