/*overload operators */

#include <iostream>

class Point
{
public:

    Point()
    {
        x = 0;
        y = 0;
    }
    ~Point(){}
    void setX(int x){this->x = x;}
    bool operator ==(const Point &point)
    {
        return this->x == point.x && this->y == point.y;
    }
    bool operator !=(const Point &point)
    {
        return !(this->x == point.x && this->y == point.y);
    }


private:
    int x;
    int y;
};

int main(){
///    (a < 10) ?(std::cout << "a < 10. a = " << a << std::endl):(a==10)?(std::cout << "a = 10." << std::endl)
    setlocale(0,"");
    Point a,b; /// a==b => a==(b)
    a.setX(4);
    (a != b) ?(std::cout << " ласс a не равен b"):(std::cout << " ласс а равен b");
	return 0;
}
