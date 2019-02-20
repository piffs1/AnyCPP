#ifndef YELLOWCOLOR_H
#define YELLOWCOLOR_H

#include "Color.h"

class YellowColor : public Color
{
    public:
        YellowColor();
        virtual void Paint() override;
        virtual ~YellowColor();

    protected:

    private:
};

#endif // YELLOWCOLOR_H
