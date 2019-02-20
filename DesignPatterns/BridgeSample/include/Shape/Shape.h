#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"

struct Vector2i /// For coordinates
{
    Vector2i(){}
    Vector2i(int &x, int &y)
    {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

class Shape
{
    public:
        Shape();
        ///virtual void Paint() = 0;
        virtual void Draw() = 0;
        void SetColor(Color *color);
        Color* GetColor();
        void SetCenter(Vector2i &v);
        void SetCenter(int &x,int &y);
        Vector2i GetCenter();
        virtual ~Shape();

    protected:
        Color *_color;
        Vector2i _center;
    private:
};

#endif // SHAPE_H
