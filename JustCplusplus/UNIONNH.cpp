#include <iostream>
#include <string>

using namespace std;

union MyUnion
{
    short int a; ///2 bytes
    int b; /// 4 bytes
    float c; /// 4 bytes
    void print(){cout << a << ' ' << b << ' ' << c << endl;}
};

int main(){

    setlocale(0,"");

    MyUnion MU;

    MU.a = 5;
    MU.print();
    MU.b = 4;
    MU.print();
    MU.c = 3.0;
    MU.print();
    return 0;
}
