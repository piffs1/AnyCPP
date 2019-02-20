#ifndef COLOR_H
#define COLOR_H

#include <iostream>

struct RGB
{
    RGB(){}
    RGB(unsigned short int &R, unsigned short int &G, unsigned short int &B)
    {this->R = R; this->G = G; this->B = B;}
    unsigned short int R;
    unsigned short int G;
    unsigned short int B;
};

class Color
{
    public:
        Color();
        virtual void Paint() = 0;
        virtual ~Color();

    protected:
        RGB _rgb;
    private:
};

#endif // COLOR_H
