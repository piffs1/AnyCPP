#include <iostream>
#include <string>

using namespace std;

template<typename T>
class MyClass
{
public:
    MyClass(T data){this->data = data;}
    ~MyClass(){}
    T GetData(){return data;}
    void SetData(T data){this->data = data;}
private:
    T data;
};

int main(){
    MyClass<int> class1(5);
    class1.SetData(7.8);
    cout << class1.GetData() << endl;

	return 0;
}
