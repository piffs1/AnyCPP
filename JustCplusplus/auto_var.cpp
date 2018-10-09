#include <iostream>
#include <typeinfo>
#include <vector>
/*
*
* typeid. auto.
*
*/


using namespace std;

int main(){

    setlocale(0,"");

    auto a = 5;

    cout << typeid(a).name() << endl;

    auto b = 5.1;

    cout << typeid(b).name() << endl;

    auto c = 'r';

    cout << typeid(c).name() << endl;

    ///auto d; - иницилизация должна быть сразу

    auto d = false;

    cout << typeid(d).name() << endl;
    vector<int> victor = {1,24,3};
    // auto it1 == vector<int>::iterator it1
    for(auto it1 = victor.begin(); it1!=victor.end(); it1++)
    {
        cout << *it1 << endl;
    }

	return 0;
}
