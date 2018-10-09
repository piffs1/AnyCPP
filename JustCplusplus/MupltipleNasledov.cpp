/* Multiple inheritance */

#include <iostream>
#include <string>

using namespace std;

class Cat
{
public:
    Cat()
    {
        cout << "������ ����������� ������ Cat!" << endl;
    }
    void Meow(){cout << "Meow!" << endl;}
    void eat(){cout << "Nom nom nom" << endl;}
};

class Dog
{
public:
    Dog()
    {
        cout << "������ ����������� ������ Dog!" << endl;
    }
    void Rawr(){cout << "RRRRRRRR!" << endl;}
    void eat(){cout << "Nyam nyam nyam" << endl;}
};

class Cat_Dog : public Dog, public Cat
{
public:
    Cat_Dog()
    {
        cout << "������ ����������� ������ Cat_Dog!" << endl;
    }
};
int main(){
    setlocale(0,"");
    Cat_Dog CD;
    CD.Meow();
    CD.Rawr();
    ((Cat)CD).eat();
    ((Dog)CD).eat();
	return 0;
}
