#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {1,1,1,1,1,1,1,6,87,8,34,7,6,6,7,90}; ///онли которые подряд убирает.
    vector<int> arr1;
    unique_copy(begin(arr),end(arr),back_inserter(arr1));
    for(auto element : arr1)
    {
        cout << element << ' ';
    }
    cout << "\n=====================\n";
    auto result = unique(begin(arr),end(arr));

    /*for (auto &element : arr)
    {
        cout << element << ' ';
    }*/
    for_each(begin(arr),end(arr),[](int a)
    {
        cout << a << ' ';
    });
	return 0;
}
