/*special templating */

#include <iostream>
#include <string>



using namespace std;

template<typename T>
class MyClass
{
public:
    void Print(T value)
    {
        cout << "Value is " << value << endl;
    }
};
template<>
class MyClass<double> ///zapret using method print
{

};

template<>
class MyClass<string>
{
public:
    void Print(string value)
    {
        cout << "It is STRING " << value << endl;
    }
};

int main(){
    MyClass<string> m;
    m.Print("1");
    MyClass<int> d;
    d.Print(5);
	return 0;
}
