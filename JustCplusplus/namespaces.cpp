/* namespaces v2 */

#include <iostream>
#include <cstring>
#define FOREVER for(;;)


using namespace std;

namespace c
{
    void Packet()
    {
        cout << "c:Packet\n";
    }
}
namespace d
{
    void Packet()
    {
        cout << "d::Packet\n";
    }
}
namespace American_Telephone_And_Telegraph
{
    string s;
}
namespace ATT = American_Telephone_And_Telegraph;
using namespace d;
using namespace c;


double pow(int a,int b)
{
    cout << "called pow(int,int)\n";
}

double pow(double a,double b)
{
    cout << "called pow(double,double)\n";
}
void f(int a)
{
    cout << "f(int a) called\na=" << a << endl;
}
double (*pntr)(double, double);
double (*pntr1)(int,int);
void alloc()
{
    FOREVER
    {
        int *a = new int[100];
    }
}
int main(){
    pntr = &pow;
    pntr(1,2);
    pntr1 = pow;
    pntr1(4.0,9.2);
    void (*pf1)(int) = &f;
    pf1(0);
    try
    {
        //alloc();
    }
    catch(const exception &ex)
    {
        cout << ex.what() << endl;
    }
#undef FOREVER ///kill macro FOREVER
    {
//        Packet();

    }

    system("pause");
	return 0;
}
