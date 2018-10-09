#include <iostream>

class A
{
public:
    A(){std::cout << "Class A constructed\n";}
    virtual ~A() = 0;
};
A::~A(){std::cout << "Class A destroyed\n";}

class B : public A
{
public:
    B(){std::cout << "Class B constructed\n";}
    ~B(){std::cout << "Class B destroyed\n";}
};

int main(){
	return 0;
}
