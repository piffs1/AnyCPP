#include <iostream>
#include <string>
#include <thread>
using namespace std;

void DoWork(int &a)
{
    cout << "STARTED DOWORK\n";
    this_thread::sleep_for(chrono::milliseconds(11000));
    a = a * 2;
    cout << "STOPPED DOWORK\n";
}

int main(){
    int a = 5;
    cout << "a = " << a << endl;
    thread th(DoWork,ref(a)); /// Передача не по переменной , а по значению. ref() - по ссылке
    /// th.detach(); успеет выполниться только первая команда, поток завершится сразу.
    for(int i = 0; i < 10; i++)
    {
        cout << "MAIN WORKDS\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    th.join(); ///Ожидаем завершения
    cout << "a = " << a << endl;
	return 0;
}
