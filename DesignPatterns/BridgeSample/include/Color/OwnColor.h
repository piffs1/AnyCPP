#ifndef OWNCOLOR_H
#define OWNCOLOR_H

#include "Color.h"

class OwnColor : public Color
{
    public:
        OwnColor(RGB &rgb);
        OwnColor(unsigned char R, unsigned char G, unsigned char B);
        virtual void Paint() override;
        virtual ~OwnColor();

    protected:

    private:
};

#endif // OWNCOLOR_H
