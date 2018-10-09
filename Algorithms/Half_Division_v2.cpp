#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
   return x*x;
}

int main()
{
    double a, b, c,e;
    a = -5;
cin>>b;
cin>>e;
    while (b - a > e){
        c = (a + b) / 2;
        if(f(b) * f(c) < 0)
            a = c;
        else
            b = c;
    }
    cout << (a + b) / 2 << endl;
    return 0;
}
