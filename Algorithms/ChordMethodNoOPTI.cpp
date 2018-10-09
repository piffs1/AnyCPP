#include <iostream> /// Function x^3 + 4*x +3 [-1;0]
#include <cmath>
double func(double x){
    return x*x*x + 4*x + 3;
}

int main(){
    double leftBorder = -1;
    double rightBorder1 = 0; /// Granica predopredelena
    double f_a = func(leftBorder);
    double f_b = func(rightBorder1);
    double rightBorder2 = rightBorder1 - ((leftBorder - rightBorder1)/(f_a-f_b))*f_b;
    double epsilon;
    std::cout << "Input accuracy of calculations =";
    std::cin >> epsilon;
    while (fabs(rightBorder1-rightBorder2)>epsilon)
    {
        rightBorder1 = rightBorder2;
        f_b = func(rightBorder1);
        rightBorder2 = rightBorder1 - ((leftBorder - rightBorder1)/(f_a-f_b))*f_b;
        std::cout << rightBorder1 << ' ' << rightBorder2 << std::endl;
    }
    std::cout << "Answer is " << rightBorder2;
    return 0;
}
