/* delegate constructor */
#include <iostream>
#include <string>

using namespace std;

class Human
{
public:

    Human(string Name) ///Если мы указываем 3 параметра, то сначала идет Human(string Name) со всеми операциями
    ///Потом Human(string Name,int Age) и Human(string Name,int Age,int Weight)
    {
        this->Name = Name;
        this->Age = 0;
        this->Weight = 0;
    }
    Human(string Name,int Age):Human(Name)
    {
        this->Age = Age;
    }
    Human(string Name,int Age,int Weight):Human(Name,Age)
    {
        this->Weight = Weight;
    }
    void DebugHuman(){cout << "Name is " << Name << ".\nAge is " << Age << ".\nWeight is " << Weight << endl;}
private:
    string Name;
    int Age;
    int Weight;
};

int main(){

    Human human("Sergey");
    human.DebugHuman();
    Human human2("Vasiliy",12);
    human2.DebugHuman();
    Human human3("Boris",60,120);
    human3.DebugHuman();
	return 0;
}
