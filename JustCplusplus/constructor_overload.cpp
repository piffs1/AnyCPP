/*
*
* constructor overload
*
*/


#include <iostream>
class Point
{
public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
    void print(){std::cout << "X = " << x << " Y = " << y << std::endl;}
    int getX(){return x;}
    int getY(){return y;}
private:
    int x,y;
};


int main(){
    Point pointA(1,2);
    pointA.print();

    Point pointB;
    pointB.print();
	return 0;
}
