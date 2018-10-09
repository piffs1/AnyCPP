/* map and multimap */

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int,string> myMap;
    myMap.insert(make_pair(1,"12"));
    myMap.insert(pair<int,string>(3,"42"));
    myMap.emplace(2,"43");
    auto it = myMap.find(2);

    for(auto &item : myMap)
    {
        cout << item.first << ' ' << item.second << endl;
    }
    cout << myMap[1] << endl;
	return 0;
}
