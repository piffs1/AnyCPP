#include <iostream>

void Foo1()
{
    std::cout << "Called Foo1() " << std::endl;
}

int Foo2()
{
    std::cout << "Called Foo2() " << std::endl;
}

void ShowInfo(int (*Foo2)())
{
    std::cout << "success" << std::endl;
}

int main(){

    ShowInfo(Foo2);
	return 0;
}
