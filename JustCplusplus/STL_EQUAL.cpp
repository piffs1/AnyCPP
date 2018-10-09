#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

struct Point
{
    Point(int x,int y){this->x = x; this->y = y;}
    int x,y;
};

int main(){

    int arr[] = {10,2,4,51,1};

    vector<int> arr1 = {10,2,4,51,1,1};

    //bool result = equal(begin(arr),end(arr),begin(arr1));
    //cout << result;
    auto result = mismatch(begin(arr),end(arr),begin(arr1));
    if(result.first == end(arr) && result.second == end(arr1))
    {
        cout << '+' << endl;
    }
    else
    {
        cout << '-' << endl;
    }
    /*int arr[] = {1,2,4,51,10};

    vector<int> arr1 = {10,2,4,51,1,1}; ///not equal need sort.
    */
    vector<Point> arr3
    {
        Point(1,3),
        Point(2,7),
        Point(3,2),
    };
    vector<Point> arr2
    {
        Point(1,3),
        Point(2,7),
        Point(3,2),
    };
    bool result1 = equal(begin(arr3),end(arr3),begin(arr2),[](const Point &p1, const Point &p2)
    {
        return p1.x == p2.x && p1.y == p2.y; ///как только он видит превое несоответствие цикл прервывается.
    });
    cout << result1;
	return 0;
}
