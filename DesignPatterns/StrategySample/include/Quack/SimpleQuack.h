#ifndef SIMPLEQUACK_H
#define SIMPLEQUACK_H

#include "IQuackable.h"

class SimpleQuack : public IQuackable
{
    public:
        SimpleQuack();
        virtual void Quack() override;
        virtual ~SimpleQuack();

    protected:

    private:
};

#endif // SIMPLEQUACK_H
