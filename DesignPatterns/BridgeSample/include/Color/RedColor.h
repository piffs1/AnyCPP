#ifndef REDCOLOR_H
#define REDCOLOR_H

#include "Color.h"

class RedColor : public Color
{
    public:
        RedColor();
        virtual void Paint() override;
        virtual ~RedColor();

    protected:

    private:
};

#endif // REDCOLOR_H
