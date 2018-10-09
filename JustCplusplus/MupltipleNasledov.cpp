/* Multiple inheritance */

#include <iostream>
#include <string>

using namespace std;

class Cat
{
public:
    Cat()
    {
        cout << "Вызван конструктор класса Cat!" << endl;
    }
    void Meow(){cout << "Meow!" << endl;}
    void eat(){cout << "Nom nom nom" << endl;}
};

class Dog
{
public:
    Dog()
    {
        cout << "Вызван конструктор класса Dog!" << endl;
    }
    void Rawr(){cout << "RRRRRRRR!" << endl;}
    void eat(){cout << "Nyam nyam nyam" << endl;}
};

class Cat_Dog : public Dog, public Cat
{
public:
    Cat_Dog()
    {
        cout << "Вызван конструктор класса Cat_Dog!" << endl;
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
