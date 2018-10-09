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
    cout << "���������� = " << value << endl;
}

int main(){
    setlocale(0,"");
    try
    {
        Foo(1);
    }
    catch(const exception &ex)
    {
        cout << "���������� �1. " << ex.what() << endl;
    }
    catch(const char* ex)
    {
        cout << "���������� �2. " << ex << endl;
    }
    /*catch(const int ex)
    {
        cout << "���������� �3. ����� ����� " << ex << endl;
    }*/
    catch(...)
    {
        cout << "���������� ����������. ������." << endl;
    }
	return 0;
}
