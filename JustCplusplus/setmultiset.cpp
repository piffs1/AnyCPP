/*set and multiset STL*/

#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(1);
    mySet.insert(3);
    ///set unique
    auto it = mySet.find(3);
    mySet.erase(1);
    if (it!=mySet.end())
    {
        cout << "Cool = " << *it << endl;
    }
    else
    {
        cout << "(((((((((((((((((((((((\n";
    }
    for(auto &item : mySet)
    {
        cout << item << endl;
    }
    cout << "===========multiset==========\b\n";
    multiset<int> ms=  {1,1,4,5,2,1,0,0,4,78}; ///мультисет позвол€ет хранить повтор значени€
    for(auto &item : ms)
    {
        cout << item << endl;
    }
    auto it1 = ms.lower_bound(1);
    auto it2 = ms.upper_bound(1);
    cout << *it1 << ' ' << *it2 << endl;
	return 0;
}
