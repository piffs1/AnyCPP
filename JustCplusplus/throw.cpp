#include <iostream>
#include <string>

using namespace std;

void Foo(int value)
{
    if(value<0)
        throw "Error. Value < 0 ";
    cout << "Переменная = " << value;
}


int main(){
    setlocale(0,"");
    try
    {
        Foo(-55);
    }
    catch(const char *ex) /// if exception (throw = string => we need char *) not string
    {
        cout << "We catched " << ex << endl;
    }
	return 0;
}
