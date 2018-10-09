/*labmda functions v2 */

#include <iostream>
#include <string>
#include <typeinfo>
#include <functional>
using namespace std;

class MyClass
{
public:
    int a = 10;
    void Msg()
    {
        cout << "msg" << endl;
    }
    void Lambda()
    {
        auto f = [this]()
        {
            ///this->Msg();
            this->a = 5;
        };
        f();
    }
};

int main(){
    setlocale(0,"");

    int a = 55;
    int b = 10;
    auto f = [&a,&b]() /// f = [=]() все переменные можем считать
    {
        cout << "f = [&a,&b](){" << endl;
        a = 33;
        b = 13;
        cout << "a = " << a << "\nb = " << b << '}' << endl;

        return 0;
    };
    auto q = [&a,b]()mutable /// f = [=]() все переменные можем считать. Mutable = & и присваиваетс€
    ///ко всем. “.е. q = [=] == q = [&] or q = [a,b] == q = [&a,&b]. ѕри выходе из функции. а - изменитс€. б - останетс€ прежней
    {
        a = 14;
        b = 32;
        cout << "q = [&a,b](){" << endl;
        cout << "a = " << a << endl << "b = " << b << '}' << endl;
        return 0;
    };
    cout << "OUT OF FUNC" << endl;
    cout << "a = " << a << "\nb = " << b << endl;
    f();
    cout << "OUT OF FUNC" << endl;
    cout << "a = " << a << "\nb = " << b << endl;
    q();
    cout << "OUT OF FUNC" << endl;
    cout << "a = " << a << "\nb = " << b << endl;
    auto z = [&]() /// f = [=]() все переменные можем считать
    {
        cout << "z = [&](){" << endl;
        a = 13;
        b = 15;
        cout << "a = " << a << endl << "b = " << b << '}' << endl;
        return 0;
    };
    z();
    cout << "OUT OF FUNC" << endl;
    cout << "a = " << a << "\nb = " << b << endl;
    cout << "======================================"<<endl;
    MyClass MC;
    MC.Lambda();
    function<int()> c = []()->int ///->тип возвращаемого значени€ or auto
    {
        return 2.23;
    };
    auto result = c();
    result = result + 2;
    cout << result;
    return 0;
}
