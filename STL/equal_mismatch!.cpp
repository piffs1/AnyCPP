/*
*   Не написаны функции equal и mismatch. Разобраться с equal_to<>{}.
*   Arthur O’Dwyer. Осваиваем C++17. Страница 50.
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

namespace STL_BOOK {

}

int main()
{
    setlocale(0, "");
    vector<int> vFirst{1,2,3,4,5,6,7,2};
    vector<int> vSecond{1,2,3,4,5,6,8,3};

    cout << equal(vFirst.begin(), vFirst.end(), vSecond.begin()) << endl; /// false
    cout << equal(vFirst.begin(), vFirst.end()-1, vSecond.begin()) << endl; /// true
    cout << equal(vFirst.begin(), vFirst.end(), vSecond.begin(), [](int first, int second)
    {
       return true;
    }) << endl; /// true

    /// mismatch возвращает первую пару итераторов, в которых было найдено несоответствие

    cout << *mismatch(vFirst.begin(),vFirst.end(), vSecond.begin()).first; /// 7
    cout << *mismatch(vFirst.begin(),vFirst.end(), vSecond.begin()).second; /// 8

    return 0;
}
