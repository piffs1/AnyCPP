#include <iostream>
#include <windows.h>
#include <math.h>
double sqr(double number){
    return number*number;
}

int main()
{
    double leftBorder,rightBorder;
    double searchFunction, number;
    double accuracy;
    label:
    std::cout << "Input left border ";
    std::cin >> leftBorder;
    std::cout << "Input right border ";
    std::cin >> rightBorder;
    std::cout << "Input number of sqrt ";
    std::cin >> number;
    std::cout << "Input accuracy of calculations ";
    std::cin >> accuracy;
    std::cout << "---------Debug Monitor--------" << std::endl;
        while(rightBorder-leftBorder>accuracy){
        searchFunction = (leftBorder+rightBorder)/2;
        std::cout << "Left Border is " << leftBorder << "\tRight Border is " << rightBorder
        << " Rb-Lb is " << rightBorder-leftBorder << std::endl;
        if (sqr(searchFunction) > number) /// sqrt(number)
            rightBorder=searchFunction;
        else
            leftBorder=searchFunction;
    }
    std::cout << "Rb-Lb is " << rightBorder-leftBorder << std::endl;
    std::cout << "---------END Debug Monitor--------" << std::endl;
    std::cout << "answer is " << (leftBorder+rightBorder)/2;
    std::cout << std::endl << "New calculations?(y/n)";
    char access;
    std::cin >> access;
    if(access=='y')
        goto label;
    return 0;
}
