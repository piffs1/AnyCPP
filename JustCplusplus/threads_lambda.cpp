#include <iostream>
#include <string>
#include <thread>
using namespace std;

int Sum(int a,int b)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\nSUM STARTED\n";
    this_thread::sleep_for(chrono::milliseconds(10000)); ///1000
    cout << "SUM STOPPED\n";
    return a+b;
}

int main(){
    int result;

    thread th([&result]()
    {
        result = Sum(2,5);
    });
    for(int i = 0; i < 10; i++)
    {
        cout << "MAIN WORKS " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    th.join();
    cout << "result = " << result << endl;
	return 0;
}
