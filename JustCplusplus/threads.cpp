#include <iostream>
#include <string>
#include <thread>
using namespace std;

class FuncMainTimer
{
public:
    FuncMainTimer()
    {
//        start = chrono::_V2::high_resolution_clock::now();
    }
    ~FuncMainTimer()
    {
        end = chrono::_V2::high_resolution_clock::now();
        chrono::duration<double> dura = end - start;
        cout << "Время выполнения :" << dura.count() << endl;
    }
private:
    chrono::time_point<chrono::_V2::steady_clock> start,end;
};


int Sum(int a,int b)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID THREAD :" << this_thread::get_id() << "======================\tSum started\t======================\n";

    this_thread::sleep_for(chrono::milliseconds(5000));

    cout << "ID THREAD :" << this_thread::get_id() << "======================\tSum stopped\t======================\n";
    return a+b;
}

int main(){
    setlocale(0,"");
   // FuncMainTimer FMT;
    auto start = chrono::_V2::high_resolution_clock::now();
    cout << typeid(start).name();
    int result;

    thread t([&result]() { result = Sum(2,5);}); /// передаем в отдельный поток

    for(size_t i = 1; i <=50;i++)
    {
        cout << "ID THREAD :" << this_thread::get_id() << "\tmain works\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }


    t.join(); ///Ожидаем окончание работы потока(че бля?)
    cout << "Sum result = " << result << endl;
    auto end = chrono::_V2::high_resolution_clock::now();
    chrono::duration<float> dura = end - start;

    cout << "Duration :" << dura.count() << "secs" << endl;

	return 0;
}
