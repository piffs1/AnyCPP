#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    setlocale(0,"");
    int mas[10];
    for(int i = 0; i < 10; i++)
        mas[i] = rand()%10;
    int b = 5;
    int *const a = &b; ///константный указатель на b
    cout << *a << endl;
    b = 6;
    cout << *a << endl; // changed a;
	const int c = 5;
                    ///a = &c; Error. Address is const.
	const int ic = 100;
    int *ip = (int*)&ic;
    *ip = 50;
    cout << &ic << " - " << ip << endl;// адрес одинаковый
    cout << ic << " - " << *ip << endl;// значения разные
	return 0;
}
