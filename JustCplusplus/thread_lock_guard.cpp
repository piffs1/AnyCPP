#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
/*
void Print(char ch)
{
    mtx.lock(); ///��������� ������, ���� ������ ����� �� ���������� � �� �����
    for(int i = 0; i < 5;i++)
    {
        for(int i = 0; i < 10; i++)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    mtx.unlock(); /// ��������� ������ ������.
}*/

void Print(char ch)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    {
        lock_guard<mutex> guard(mtx);
        cout << "����� � " << this_thread::get_id() << endl;
        for(int i = 0; i < 5;i++)
        {
            for(int i = 0; i < 10; i++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout << endl;
        }
        cout << "����� � " << this_thread::get_id() << " ����������� ������." << endl;
    }
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

}

int main(){
    setlocale(0,"");
    thread th1(Print,'x');
    thread th2(Print,'y');
    th1.join();
    th2.join();
	return 0;
}
