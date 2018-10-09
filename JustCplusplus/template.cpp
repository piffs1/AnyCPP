#include <iostream>
///template<class T>
template<class T1,typename T2>
T1 Sum(T1 a, T2 b)
{
    std::cout << &a << ' ' << &b << std::endl;
    return a+b;
}


int main(){
    std::cout << Sum(1.2,1);
	return 0;
}
