/* Friend function in classes */


#include <iostream>



class TestClass;
class Test
{
public:
    void ShowData(){std::cout << "Data = " << data << std::endl;}
private:
    friend void fleX(TestClass &value,Test &test);
    int data;
};

class TestClass
{
public:
    TestClass()
    {
        x = 0;
        y = 0;
    }
    int & operator[](int index){return a1[index];}
    void ShowXY()
    {
        std::cout << "x = " << x << " y = " << y << std::endl;
    }
private:
    int a1[6] = {1,2,3,4,5,6};
    int x;
    int y;
    friend void fleX(TestClass &value,Test &test); ///Тут все и так понятно. Дружеская функцияможет быть определена везде.
};


void fleX(TestClass &value,Test &test)
{
    value.x = 5;
    value.y = 6;
    test.data = 4;
}

int main(){
    TestClass b;
    b.ShowXY();
    Test test;
    fleX(b,test);
    b.ShowXY();
    test.ShowData();
	return 0;
}
