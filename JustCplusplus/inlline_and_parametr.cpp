/* inline functions and parameter in function */

#include <iostream>

void foo(int a = 5)
{
    for (int i = 0; i < a; i++)
        std::cout << "i = "  << i << std::endl;
}

inline int sum(int a,int b)
{
    return a+b;
}

int main(){
    foo();
    std::cout << "/------------/" << std::endl;
    foo(3);
    std::cout << "sum = " << sum(1,2) << std::endl;
    /// inline ���������� ��� ��������� ����������� �������. ��� ������������� ��������� � ���� �������� ������� �� �������.
	return 0;
}
