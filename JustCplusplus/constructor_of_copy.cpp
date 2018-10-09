/* constructor of copy */

#include <iostream>

class Point
{

public:
    int sizemin1;
    Point(int a,int size)
    {
        arraySize = size;
        std::cout << "Hi " << this << std::endl;
        this->a = a;
        b = new int[size];
        for(int i = 0; i < size;i++)
            b[i] = i;
    }

    Point(const Point &point) ///конструктор копирования
    {
        this->arraySize = point.arraySize;
        std::cout << "Called copying constructor " << this << std::endl;
        this->b = new int[point.arraySize];
        for(int i = 0; i < point.arraySize;i++)
            this->b[i] = point.b[i];
    }

    ~Point()
    {
        std::cout << "Goodbye " << this << std::endl;
        delete[] b;
    }
    void setA(int a){this->a = a;}
    int getA(){return a;}
private:
    int a;
    int *b;
    int arraySize;
};

Point my_f2()
{

    std::cout << "my_f2() is working\n";
    Point point(3,6);

    return point;
}

void my_f(Point point) ///Аргумент функции копируется побитно и в результате мы имеем идентичный класс по всем значениям
{ ///Именно поэтому вызовов конструкторов меньше, чем вызовов деструкторов
    std::cout << "new class point with address " << &point << std::endl;
    std::cout << "previous a = " << point.getA() << std::endl;
    point.setA(4);
    std::cout << "new a = " << point.getA() << std::endl;
}

int main(){

    Point point(5,6);
    //my_f(point);
    std::cout << "================\n";
    //point = my_f2();
    point.sizemin1 = 5; /// ??????????
    Point pointB(point); ///Конструктор копирования
    std::cout << pointB.getA() << std::endl;
    return 0;
}
