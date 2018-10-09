#include <iostream>
#include <array>

using namespace std;

const int SIZE = 0;

void PrintArray(const array<int,4> &arr)
{
    for(auto it = arr.cbegin(); it!=arr.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
}

int main() {
	array<int, 4> arr;
	arr.fill(14);
    try
    {
        //cout << "arr[5] = " << arr.at(3);
    }
    catch (const std::exception &ex)
    {
        cout << ex.what() << endl;
    }
    PrintArray(arr);
	//cout << arr[2] << endl;
		return 0;
}
