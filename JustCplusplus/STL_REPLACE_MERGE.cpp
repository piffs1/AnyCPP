#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    int arr[] = {1,6,2,2,3,6,4,1,10,6,54};
    sort(begin(arr),end(arr));
    for(auto &element : arr)
    {
        cout << element << ' ';
    }
    replace(begin(arr),end(arr),6,3); ///6 меняется на 3
    replace_if(begin(arr),end(arr),[](int a)
    {
        return a>9;
    },32);
    cout << endl;
    int arr1[] = {5,2,3,67,4,21};
    int arr2[] = {67,2,4,6,1,2,5};
    sort(begin(arr1),end(arr1));
    sort(begin(arr2),end(arr2));
    vector<int> c;
    merge(begin(arr1),end(arr1),begin(arr2),end(arr2),back_inserter(c));
    for(auto &element : arr)
    {
        cout << element << ' ';
    }
    cout << endl;
    cout << "arr1" << endl;
    for(auto &element : arr1)
    {
        cout << element << ' ';
    }
    cout << endl;
    cout << "arr2" << endl;
    for(auto &element : arr2)
    {
        cout << element << ' ';
    }
    cout << endl << "Merge(arr1,arr2)" << endl;
    for(auto &element : c)
    {
        cout << element << ' ';
    }
    cout << endl << "Deleting repeat elements...\n";
    auto result = unique(c.begin(),c.end());
    c.erase(result,c.end());
    for(auto &element : c)
    {
        cout << element << ' ';
    }
	return 0;
}
