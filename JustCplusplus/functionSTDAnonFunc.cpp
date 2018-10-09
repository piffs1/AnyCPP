/* lambda functions */

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

void Foo()
{
    cout << "Foo()" << endl;
}

void Foo2()
{
    cout << "Foo2() " << endl;
}

void Bar(int a)
{
    if(a>0 && a<40)
        cout <<"Bar = " << a <<  endl;
}

void Bar1(int a)
{
    if(a % 2 == 0)
        cout << "Bar1 = " << a << endl;
}

int Sum(int a,int b)
{
    return a+b;
}

void DoWork(vector<int> &vec, function<void(int)> f)
{
    for(int el : vec)
    {
        f(el);
    }
}

void DoWork2(vector<int> &vec, vector<function<void(int)>> functionVector)
{
    for(auto el : vec)
    {
        for(auto &FV : functionVector)
        {
            FV(el);
        }
    }
}


int main(){
    setlocale(0,"");
    function<void()>  f;
    ///function like pointer
    f = Foo2;
    f();
    function<int(int,int)> f1;
    f1 = Sum;

    cout << f1(1,2) << endl;
    vector<int> vc = {1,2,321,4521,521,521,421,3,2131,3123,32,1,0};
    DoWork(vc,Bar1);
    vector<function<void(int)>> fVector;
    fVector.push_back(Bar);
    fVector.push_back(Bar1);
    DoWork2(vc,fVector);
    ///function<тип возвращаемого значения(параметры функции)>
    cout << "==========================" << endl;
    function<void(int)>  f2;
    f2 = [](int a)
    {
        cout << "Anon func(" << a << ')' << endl;
    };
    f2(2);
    DoWork(vc,f2);
    DoWork(vc,[](int a)
    {
        bool IL = true;
        if(IL)
            cout << "C++ very interesting language of programming. Func(" << a << ')' << endl;
    });

	int z = 0;
	int s = 0;
	auto f3 = [&s]()
	{
	    cout << "executing anon func... s =" << s << endl;
	    s = 5;
	    cout << "s = " << s << endl;
        return 1;
	};
	auto q = f3();
    cout << "out of func " << s << endl;

	return 0;
}
