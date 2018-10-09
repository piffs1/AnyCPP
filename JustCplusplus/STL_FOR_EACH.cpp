#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Foo(int a)
{
    cout << a << ' ';
}

int main(){

    int arr[] = {1,6,2,1,7,21};
    for_each(begin(arr),end(arr),[](int &a)
    {
        cout << a++ << ' ';
    });
    cout << endl;
    for( auto &a : arr)
    {
        Foo(a++);
    }
    cout << endl;
    for( auto &a : arr)
    {
        Foo(a);
    }

	return 0;
}
