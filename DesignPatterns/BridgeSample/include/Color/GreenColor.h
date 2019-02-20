#ifndef GREENCOLOR_H
#define GREENCOLOR_H

#include "Color.h"

class GreenColor : public Color
{
    public:
        GreenColor();
        virtual void Paint() override;
        virtual ~GreenColor();

    protected:

    private:
};

#endif // GREENCOLOR_H
