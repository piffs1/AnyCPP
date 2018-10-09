#include <iostream>
using std::cout;
class A
{
public:
    virtual void method() {std::cout << "A method\n";}
    A(){std::cout << "Конструктор класса А\n";}
    virtual ~A(){std::cout << "Деструктор класса A\n";}
    void aFUNC(){};
};

class B : public A
{
public:
    virtual void method() {std::cout << "B method\n";}
    B(){std::cout << "Конструктор класса В\n";}
    ~B()override{std::cout << "Деструктор класса B\n";}
    void bFUNC(){};
};

class C : public B
{
public:
    virtual void method() {std::cout << "C method\n";}
    C(){std::cout << "Конструктор класса C\n";}
    ~C(){std::cout << "Деструктор класса C\n";}
    void cFUNC(){};
};

int main(){
    setlocale(0,"");
	A *bptr = new B;
	bptr->aFUNC();
    ///bptr->bFUNC(); A *bptr = new B; error class A has no memeber bFunc();
    bptr->method();
    delete bptr;
	return 0;
}
