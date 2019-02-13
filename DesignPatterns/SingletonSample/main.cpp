#include <iostream>
#include "Singleton.h"


int main()
{
    std::cout << "======================================\n";
    Singleton &singleTon = Singleton::getInstance();
    std::cout << "======================================\n";
    Singleton &singleTon1 = Singleton::getInstance();
    std::cout << "======================================\n";
    std::cout << "Address singleton " << &singleTon << '=' << &singleTon1 << std::endl;
    std::cout << "======================================\n";
    return 0;
}
