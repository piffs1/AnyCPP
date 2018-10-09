/* Multicatching exceptions */

#include <iostream>
#include <string>

using namespace std;


void Foo(int value)
{
    if(value<0)
        throw "ERROR. VALUE < 0";
    if(value==0)
        throw "ERROR. VALUE == 0";
    if(value==1)
        throw 1;
    cout << "Переменная = " << value << endl;
}

int main(){
    setlocale(0,"");
    try
    {
        Foo(1);
    }
    catch(const exception &ex)
    {
        cout << "Исключение №1. " << ex.what() << endl;
    }
    catch(const char* ex)
    {
        cout << "Исключение №2. " << ex << endl;
    }
    /*catch(const int ex)
    {
        cout << "Исключение №3. Число равно " << ex << endl;
    }*/
    catch(...)
    {
        cout << "Исключение №последнее. Ошибка." << endl;
    }
	return 0;
}
