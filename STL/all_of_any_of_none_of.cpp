#include <algorithm>
#include <functional>
#include <cassert>
#include <iostream>
#include <set>

#define END_NAMESPACE }
using namespace std;

namespace STL_BOOK {
template<class Iterator, class Predicate>
Iterator find_if(Iterator first, Iterator last, Predicate pred)
{
    for(; first != last; ++first) {
        if(pred(*first)) {
            return first;
            /// Вычисления по короткой схеме.
            /// Как только найдет первое, сразу же возвращает.
        }
    }
    return last;
}

template<class Iterator, class Predicate>
bool all_of(Iterator begin, Iterator end, Predicate pred)
{
    return (find_if_not(begin,end,pred) == end);
}

template<class Iterator, class Predicate>
bool any_of(Iterator begin, Iterator end, Predicate pred)
{
    return (find_if(begin,end, pred) != end);
}

template<class Iterator, class Predicate>
bool none_of(Iterator begin, Iterator end, Predicate pred)
{
    return (find_if(begin,end,pred) == end);
}

END_NAMESPACE

int main()
{
    setlocale(0, "");
    vector<int> vLocal{1,2,3,4,5,6,5,7,8};
    /// all_of : Предикат возвращает true для всех элементов в диапазоне [first, last).
    /// any_of : Предикат возвращает значение true для хотя бы одного элемента в диапазоне [first, last).
    /// none_of: Предикат не возвращает значение true ни для одного элемента в диапазоне [first, last).

    function<bool(int)> GreaterZero = [](int x)
    {
        return x > 0;
    };

    function<bool(int)> GreaterOne = [](int x)
    {
        return x > 1;
    };

    function<bool(int)> LessZero = [](int x)
    {
        return x < 0;
    };

    cout << all_of(vLocal.begin(), vLocal.end(), GreaterZero) << endl;; /// true

    cout << all_of(vLocal.begin(), vLocal.end(), GreaterOne) << endl;; /// false

    cout << any_of(vLocal.begin(), vLocal.end(), GreaterZero) << endl; /// true

    cout << any_of(vLocal.begin(), vLocal.end(), LessZero) << endl; /// false

    cout << none_of(vLocal.begin(), vLocal.end(), GreaterZero) << endl; /// false

    cout << none_of(vLocal.begin(), vLocal.end(), LessZero) << endl; /// true

    return 0;
}
