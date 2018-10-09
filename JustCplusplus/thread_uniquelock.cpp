#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

/// unique_lock == lock_guard. Можно указывать где будет начинаться блокироваться с помощью аргумента defer_lock.
/// гибкий локер
void Print()
{

    unique_lock<mutex> ul(mtx,defer_lock);

    this_thread::sleep_for(chrono::milliseconds(2000));

    ul.lock();

    for(int i = 0; i < 5; i++)
    {
        for(int i = 0; i < 10; i++)
        {
            cout << '^';
        }
        cout << endl;
    }

    cout << endl;
    ul.unlock();
}

int main(){
    thread th(Print);
    th.join();
	return 0;
}
