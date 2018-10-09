#include <iostream>
#include <string>
#include <thread>
using namespace std;

void DoWork(int a,int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\n=============\tDoWork STARTED\t=================" << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "a + b = " << a + b << endl;

    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\n=============\tDoWork STOPPED\t=================" << endl;
}

int main(){
    thread th(DoWork,2,4);
    for(int i = 0;true;i++)
    {
        cout << "ID THREAD = " << this_thread::get_id() << "\tmain works\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();
	return 0;
}
