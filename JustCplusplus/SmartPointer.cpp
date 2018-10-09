/* Smart Pointer*/

#include <iostream>
#include <string>

using namespace std;
template<typename T>
class SmartPointer
{
public:

    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
    }
    ~SmartPointer()
    {
        delete ptr;
    }

    T& operator*()
    {
        return *ptr;
    }

private:
    T *ptr;
};

int main(){

    setlocale(0, "");
    SmartPointer<int> ptr = new int(15); ///New int и возвращает указатель
    cout << "SIZE OF PTR " << sizeof(ptr) << endl;

    cout << "OLD VALUE PTR = " << *ptr << endl;
    *ptr = 12;
    cout << "NEW VALUE PTR = " << *ptr << endl;

	return 0;
}
