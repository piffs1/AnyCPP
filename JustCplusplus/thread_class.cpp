#include <iostream>
#include <thread>

using namespace std;

class MyClass
{
public:
    void DoWork();
    void DoWork1(int a);
};

void MyClass::DoWork()
{
    this_thread::sleep_for(chrono::milliseconds(4000));
    cout << "DOWORK CREATED\n";
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "DOWORK STOPPED\n";
}

void MyClass::DoWork1(int a)
{
    cout << "a = " << a << endl;
}

int main(){
    MyClass m;
    thread th([&m]()
    {
        m.DoWork();
    });
    thread th1([&m]()
    {
        m.DoWork1(5);
    });
	for(int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "main works " << i << endl;
    }
    th.join();
    th1.join();
	return 0;
}
