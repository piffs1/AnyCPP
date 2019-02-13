#ifndef UPGRATABLEDUCK_H
#define UPGRATABLEDUCK_H

#include "BaseDuck.h"


class UpgratableDuck : public BaseDuck
{
    public:
        UpgratableDuck();
        virtual void Drive() override;
        void setQuackMode(IQuackable *quack);
        void setFlyMode(IFlyable *fly);
        void Debug();
        virtual ~UpgratableDuck();

    protected:

    private:
};

#endif // UPGRATABLEDUCK_H
