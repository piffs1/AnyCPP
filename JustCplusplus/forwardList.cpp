/* forward list C++ */

#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

int main(){
    forward_list<int> fl; ///односвязный список
    for(int i = 0; i < 5; i++)
        fl.push_front(i);
    for(auto el : fl)
    {
        cout << el << endl; ///fl.insert_after(iterator,data); before_begin)))
    }
	return 0;
}
