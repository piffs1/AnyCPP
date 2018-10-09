#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "Called constructor of class A!!!" << std::endl;
    }
    A(std::string msg)
    {
        this->msg=msg;
    }
    ~A()
    {
        std::cout << "Called destructor of class A!!!" << std::endl;
    }
    void PrintMSG(){std::cout << msg << std::endl;}
private:
    std::string msg = "Hello Class!!";
};

class B : public A
{
public:
    B():A("123") /// �� ��������� ����������� ������ A(). �� ��������� B():A().
    {
        std::cout << "Called constructor of class B!!!" << std::endl;
    }
    ~B()
    {
        std::cout << "Called destructor of class B!!!" << std::endl;
    }
};

class C : public B
{
public:
    C()
    {
        std::cout << "Called constructor of class C!!!" << std::endl;
    }
    ~C()
    {
        std::cout << "Called destructor of class C!!!" << std::endl;
    }
};

class D
{
public:
    D(int a)
    {
        this->a = a;
    }
    int GetA(){return a;}
private:
    int a;
};

class E : public D
{
public:
    E():D(2)
    {
    }
};

/// C ���������� �� � ���������� �� �. ������� ���������� ����������� � ������, ����� ����������� � ������, ����� ����������� � ������
int main(){
    C c;
    c.PrintMSG();
    E e;
    std::cout << std::endl << "e.a = " << e.GetA() << std::endl;
	return 0;
}
