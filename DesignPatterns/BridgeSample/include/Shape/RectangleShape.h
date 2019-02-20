#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "Shape.h"

class RectangleShape : public Shape
{
    public:
        RectangleShape();
        RectangleShape(int x,int y);
        RectangleShape(Vector2i &v);
        virtual void Draw() override;
        virtual ~RectangleShape();

    protected:
        Vector2i _size;
    private:
};

#endif // RECTANGLESHAPE_H
