#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "ID THREAD = " << this_thread::get_id() << "\tDoWork\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void DoWork2()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "ID THREAD = " << this_thread::get_id() << "\tDoWork2\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}

int main(){

    cout << "START MAIN" << endl;

    thread th(DoWork);
    thread th2(DoWork2);
    ///th.join() - ���� ����� �� ��������� ������, �� ������� ���������� DoWork �� ������ ������, � ����� main � ������
    ///th.detach() ���� main �������� ������ ������, �� ����� ��������� ������ � DoWork ����������� �� 5 ��������
    for(int i = 0; i < 10; i++)
    {
        cout << "ID THREAD = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join(); /// ���������� ������ ������ DoWork
    th2.join();
    /// ����� ���� ������ �� join, �� �������� ����� �����������
    cout << this_thread::get_id() << endl;

    cout << "END MAIN" << endl;

	return 0;
}
