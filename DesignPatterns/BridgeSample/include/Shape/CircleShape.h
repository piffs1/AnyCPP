#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.h"

class CircleShape : public Shape
{
    public:
        CircleShape();
        CircleShape(unsigned int radius);
        virtual void Draw() override;
        void SetRadius(unsigned int radius);
        unsigned int GetRadius();
        virtual ~CircleShape();

    protected:
        unsigned int _radius;
    private:
};

#endif // CIRCLESHAPE_H
