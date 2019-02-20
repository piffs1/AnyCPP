#ifndef SQUARESHAPE_H
#define SQUARESHAPE_H

#include "Shape.h"

class SquareShape : public Shape
{
    public:
        SquareShape();
        virtual void Draw() override;
        virtual ~SquareShape();

    protected:

    private:
};

#endif // SQUARESHAPE_H
