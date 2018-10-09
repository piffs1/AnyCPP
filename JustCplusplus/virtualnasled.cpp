#include <iostream>
#include <string>

using namespace std;

class Predok
{
public:
    Predok()
    {
        cout << "Predok constructed" << endl;
    }
    ~Predok()
    {
        cout << "Predok destroyed" << endl;
    }
    int IQ;
};

class Class1 : virtual public Predok ///public Predok
{
public:
    Class1()
    {
        cout << "Class1 constructed" << endl;
    }
    ~Class1()
    {
        cout << "Class1 destroyed" << endl;
    }
};

class Class2 : public Predok ///public Predok
{
public:
    Class2()
    {
        cout << "Class2 constructed" << endl;
    }
    ~Class2()
    {
        cout << "Class2 destroyed" << endl;
    }
};

class UnionC12 : public Class1, public Class2
{
public:
    UnionC12()
    {
        cout << "UnionC12 constructed" << endl;
    }
    ~UnionC12()
    {
        cout << "UNIONC12 destroyed" << endl;
    }
};


int main(){
    UnionC12 C12;
	return 0;
}
