#ifndef NOQUACK_H
#define NOQUACK_H

#include "IQuackable.h"

class NoQuack : public IQuackable
{
    public:
        NoQuack();
        virtual void Quack() override;
        virtual ~NoQuack();

    protected:

    private:
};

#endif // NOQUACK_H
