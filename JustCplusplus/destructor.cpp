/* destructor */

#include <iostream>

#define CLASS_DEBUG 1
///this - это указатель на адрес класса
class Point
{
public:
    Point(int a)
    {
        this->a = a;
        mas = new int[a];
#if CLASS_DEBUG == 1
        std::cout << "Class Point with int(" << a << ") was called!\n";
#endif // CLASS_DEBUG
        for(int i = 0; i < a; i++)
            mas[i] = i;
    }
    ~Point()
    {
#if CLASS_DEBUG== 1
        std::cout << "Point's destructor with int(" << a <<") was called!\n";
#endif // CLASS_DEBUG
        delete[] mas;
    }
private:
    int x;
    int y;
    int a;
    int *mas;
};
#if CLASS_DEBUG == 1
void test_f()
{
    std::cout << "test_f() begins" << std::endl;
    Point pointA(3);
    std::cout << "test_f() ends" << std::endl;
}
#endif // CLASS_DEBUG
int main(){
    Point pointA(1);
    Point pointB(2);
#if CLASS_DEBUG == 1
    test_f();
#endif // CLASS_DEBUG
    Point pointC(4);
	return 0;
}
