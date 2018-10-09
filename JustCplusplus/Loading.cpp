/* Multithreading application */

#include <iostream>
#include <string>
#include <thread>
using namespace std;

void Loading()
{
    cout << "Loading";
    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << '.';
    }
}

int main(int argc,char argv[]){
    setlocale(0,"");
    cout << "Интервал обновления 1 секунда. Сколько секунд будет выполняться главная операция? ";
    int secnds;
    cin >> secnds;
    thread th(Loading);
    cout << "Main started\n";
    this_thread::sleep_for(chrono::seconds(secnds));
    th.detach();

    cout << "\nLoading Complete!\n";
    cout << "Main stopped\n";
	return 0;
}
