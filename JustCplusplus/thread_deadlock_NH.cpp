#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx1,mtx2;

void Print()
{
    mtx1.lock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX1 LOCKED\n";
    this_thread::sleep_for(chrono::milliseconds(1231));

    mtx2.lock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX2 LOCKED\n";
    for(int i = 0; i < 5; i++)
    {
        for(int i = 0; i < 10; i++)
        {
            cout << 'x';
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;
    mtx1.unlock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX1 UNLOCKED\n";
    mtx2.unlock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX2 UNLOCKED\n";
}

void Print1()
{
    mtx1.lock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX1 LOCKED\n";
    this_thread::sleep_for(chrono::milliseconds(1233));

    mtx2.lock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX2 LOCKED\n";
    for(int i = 0; i < 5; i++)
    {
        for(int i = 0; i < 10; i++)
        {
            cout << '#';
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;
    mtx1.unlock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX1 UNLOCKED\n";
    mtx2.unlock();
    cout << "ID THREAD = " << this_thread::get_id() << '\n' << "MTX2 UNLOCKED\n";
}

int main(){
    thread th1(Print);
    thread th2(Print1);
    th1.join();
    th2.join();
	return 0;
}
