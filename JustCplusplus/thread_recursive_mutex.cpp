#include <iostream>
#include <string>
#include <mutex>
#include <thread>
using namespace std;


recursive_mutex rm;

void Foo(int a)
{
    rm.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(300));

    if (a<=1)
    {
        cout << endl;
        rm.unlock();
        return;
    }

    a--;
    Foo(a);
    rm.unlock();
}

int main(){
    thread th(Foo,10);
    thread th1(Foo,15);
    th1.join();
    th.join();
	return 0;
}
