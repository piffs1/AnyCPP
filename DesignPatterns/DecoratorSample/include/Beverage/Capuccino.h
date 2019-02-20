#ifndef CAPUCCINO_H
#define CAPUCCINO_H
#include "BeverageBase.h"

class Capuccino : public BeverageBase
{
    public:
        Capuccino();
        virtual double GetCost() override;
        virtual ~Capuccino();

    protected:

    private:
};

#endif // CAPUCCINO_H
