#ifndef WHITECOLOR_H
#define WHITECOLOR_H

#include "Color.h"

class WhiteColor : public Color
{
    public:
        WhiteColor();
        virtual void Paint() override;
        virtual ~WhiteColor();

    protected:

    private:

};

#endif // WHITECOLOR_H
