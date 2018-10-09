#include <iostream>
#include <string>
#include <algorithm>
#include <List>

using namespace std;

typedef list<int> int_list;
int main(){

    int_list array = {1,2,3,4,5,0,8};
    /*for_each(int var in array)
    {
        cout << var << endl;
    }*/
    for(const int &var : array) ///onlyread
    {
        cout << var << ',';

    }
	return 0;
}
