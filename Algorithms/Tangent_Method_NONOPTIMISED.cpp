#include <iostream> /// Function x^3 + 4*x + 2 [-1;0]
#include <cmath>
double func(double x){
    return x*x*x + 4*x + 2;
}

double dfunc(double x){
    return 3*x*x + 4;
}
double abs(double x){
    if (x<0) return -1 * x;
}
int main()
{
    double x;
    double leftBorder = -1; /// Coming from left border
    double curFunc,curdFunc;
    double nextFunc,nextdFunc;
    double a1,a2;
    double accuracy;
    std::cout << "Input accuracy of calculations ";
    std::cin >> accuracy;
    curFunc = func(leftBorder);
    curdFunc = dfunc(leftBorder);
    a1 = leftBorder - (curFunc/curdFunc);
    nextFunc = func(a1);
    nextdFunc = dfunc(a1);
    a2 = a1 - (nextFunc/nextdFunc);
    std::cout << "Current function = " << curFunc << ' ' << "\t\tCurrent dFunction = " << curdFunc << ' ' << "\t\tCurrent A1 = " << a1 << std::endl;
    std::cout << "Next function = " << nextFunc << ' ' << "\tNext dFunction = " << nextdFunc << ' ' << "\tCurrent A2 = " << a2 << std::endl;
    std::cout << std::endl;
    while(fabs(a2-a1)>accuracy)
    {
        a1 = a2;
        a2 = a1 - (func(a1)/dfunc(a1));
    }
    std::cout << "Answer is " << a2;
    return 0;
}
