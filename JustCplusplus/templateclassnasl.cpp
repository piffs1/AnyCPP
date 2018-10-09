#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
template<class T>
class MyClass
{
public:
    MyClass(T data)
    {
        this->data = data;
    }
protected:
    T data;
};

template<class T>
class MyClass_Nasl : public MyClass<T> /// public MyClass<int>
{
public:
    MyClass_Nasl(T data) : MyClass<T>(data) ///2007 year
    {

    }
    void ShowDataType()
    {
        cout << "Type " << typeid(MyClass_Nasl<T>::data).name() << endl; ///typeid(this->data)
    }
};

int main(){
    MyClass_Nasl<int> MCN(5);
    MCN.ShowDataType();
	return 0;
}
