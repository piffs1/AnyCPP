#include <iostream>


using namespace std;
    
struct X {};

int main()
{
    
    const int a = 2;
    decltype(a) x3 = 2; /// eq const int x3 = 2;
    cout << typeid(x3).name() << endl; /// int
    
    static_assert(a==x3, "failed"); /// static_assert ->Проверка на этапе компиляции. Солидно


    X x;
    decltype(x) x4;
    cout << typeid(x4).name() << endl; /// struct X

    return 0;
}
