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
    Point operator +(const Point &point)
    {
        Point temp;
        temp.x = this->x + point.x;
        temp.y = this->y + point.y;
        return temp;
    }
    Point &operator ++()///prefix
    {
        this->x+=1;
        this->y++;
        return *this;
    }
    Point &operator ++(int value)///postfix
    {
        Point temp(*this);

        this->x++;
        this->y++;

        return temp;
    }
    Point &operator --()
    {
        this->x--;
        this->y--;
        return *this;
    }
    void ShowPoint()
    {
        std::cout << "X = " << x << "\t Y = " << y << '\n';
    }
    ~Point(){};
private:
    int x;
    int y;
};

int main(){
    Point pointA(1,2);
    Point pointB(3,6);
    Point pointC = pointA + pointB; ///pointC = pointA.operator+(pointB);
    pointA.ShowPoint();
    pointB.ShowPoint();
    pointC.ShowPoint();
    ++pointA;
    pointA.ShowPoint();
    pointA++;
    pointA.ShowPoint();
    --pointA;
    pointA.ShowPoint();
	return 0;
}
