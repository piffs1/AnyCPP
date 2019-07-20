/*
*   Не написаны функции equal и mismatch. Разобраться с equal_to<>{}.
*   Книга Arthur O’Dwyer. Осваиваем C++17. Страница 50.
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cassert>

namespace STL_BOOK {
    template<class Iterator>
    bool equal(Iterator first1, Iterator last1, Iterator first2)
    {
        for(; first1 != last1; ++first1, ++first2) {
            if (*first1 != *first2) {
                return false;
            }
        }
        return true;
    }

    template<class Iterator,class BinaryPred>
    bool equal(Iterator first1, Iterator last1, Iterator first2, BinaryPred pred)
    {
        for(; first1 != last1; ++first1, ++first2) {
            if (!pred(*first1,*first2)) {
                return false;
            }
        }
        return true;
    }

    template<class Iterator, class T>
    std::pair<Iterator,Iterator> equal_range(Iterator first1, Iterator last1, const T& value)
    {
        return std::make_pair(lower_bound(first1,last1,value), upper_bound(first1,last1,value));
    }

    template<class Iterator>
    std::pair<Iterator, Iterator> mismatch(Iterator first1, Iterator last1, Iterator first2)
    {
        while (first1 != last1 && *first1 == *first2) {
            ++first1;
            ++first2;
        }
        return std::make_pair(first1,first2);
    }

}


using namespace std;

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

    cout << *equal_range(vFirst.begin(), vFirst.end(), 2).first << ' ' << *equal_range(vFirst.begin(),vFirst.end(),2).second << endl;
    /// equal_range(ItBegin,ItEnd, value) возвращает пару итераторов pair<ItB,ItE>
    /// по сути этот алгоритм можно повторить кобминацией lower_bound и upper_bound
    /// Первый итератор будет возвращать итератор на первый элемент value(aka lower_bound)
    /// Второй итератор будет возвращать итератор на первый элемент после последнего value
    /// т.е. {1,2,2,2,2,2,3} itB будет указывать на первую двойку, itE на тройку(первую цифру после 2)
    /// mismatch возвращает первую пару итераторов, в которых было найдено несоответствие

    cout << *mismatch(vFirst.begin(),vFirst.end(), vSecond.begin()).first; /// 7
    cout << ' ';
    cout << *mismatch(vFirst.begin(),vFirst.end(), vSecond.begin()).second; /// 8



    return 0;
}
