/* Binary Search v2 */

#include <iostream>

using namespace std;
const int SIZE = 5;
int matrix[SIZE][SIZE] =
{
    1,  4,  7,  11,  15,
    2,  5,  8,  12,  19,
    3,  6,  9,  16,  22,
    10, 13, 14, 17,  24,
    18, 21, 23, 26,  30,
};

bool BinSearch(const int *a, const int &value) //
{
    int start = 0;
    int end = SIZE-1;
    int mid;
    for(int i = 0;i <SIZE;i++)
    {
        cout << a[i] << '\t';
    }
    while(start<=end)
    {
        mid = (start+end)/2;
        if(a[mid]==value)
            return true;
        if(a[mid]<value)
            start = mid+1;
        else
            end = mid-1;
    }
    return false;
}

int main()
{
    int value;
    for(int i = 0; i < SIZE;i++)
    {
        for(int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
    cout << "The searching value is ";
    cin >> value;
    for(int i = 0 ; i < SIZE; i++)
    {
        if(BinSearch(matrix[i],value))
            cout << "Found!";
        else
            cout << "Not found";
        cout << endl;
    }

    return 0;
}
