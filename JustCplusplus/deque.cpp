/* deque */

#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq = {12,4,2,1,21,2};
    cout << "Size is " << dq.size() << endl;
    for(auto it = begin(dq); it!= end(dq);it++)
        cout << *it << ' ';
    cout << endl;
    for(int i = 0; i < dq.size(); i++)
        cout << dq[i] << ' ';
    cout << endl;
    dq.assign(dq.size(),2);
    for(int i = 0; i < dq.size(); i++)
        cout << dq[i] << ' ';
    cout << endl;
	return 0;
}
