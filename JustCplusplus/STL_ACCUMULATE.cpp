/* accumulate */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){


    int b[] = {1,4,1,2,3,5,8,1,10,71};
    int c = accumulate(begin(b),end(b),1,[](int a, int& b) ///accumulate(nachalo,konec, point otscheta, predicat)
    { 
       return a+b;
    });
	///this accumulate(int a,int b) = a (+/*-) b 
    cout << "C = " << c << endl;
	return 0;
}
