#ifndef EXOTICQUACK_H
#define EXOTICQUACK_H

#include "IQuackable.h"

class ExoticQuack : public IQuackable
{
    public:
        ExoticQuack();
        virtual void Quack() override;
        virtual ~ExoticQuack();

    protected:

    private:
};

#endif // EXOTICQUACK_H
