#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

namespace STL_BOOK {

template<typename Iterator, typename Predicate>
int count_if(Iterator begin, Iterator end, Predicate pred)
{
    int nCount = 0;
    for (Iterator it = begin; it != end; ++it) {
        if (pred(*it)) {
            nCount++;
        }
    }
    return nCount;
}
/// count(Iter,Iter,value) похожа, но ищет по значению, а не предикату
}

int main()
{
    vector<int> vLocalEmpty;
    vector<int> vLocal{3,4};
    list<int> lstEmpty;
    list<int> lstLocal{3,4,5};
    function<bool(int)> func_isFive;

    func_isFive = [](int a_nValue) { return a_nValue == 5; };

    bool bExpression =
    (
        STL_BOOK::count_if(vLocalEmpty.begin(), vLocalEmpty.end(), func_isFive) == count_if(vLocalEmpty.begin(), vLocalEmpty.end(), func_isFive)
    );
    assert(bExpression); /// TRUE

    bExpression =
    (
        STL_BOOK::count_if(vLocal.begin(), vLocal.end(), func_isFive) == count_if(vLocal.begin(), vLocal.end(), func_isFive)
    );
    assert(bExpression); /// TRUE
    bExpression =
    (
        STL_BOOK::count_if(lstEmpty.begin(), lstEmpty.end(), func_isFive) == count_if(lstEmpty.begin(), lstEmpty.end(), func_isFive)
    );
    assert(bExpression); /// TRUE

    bExpression =
    (
        STL_BOOK::count_if(lstLocal.begin(), lstLocal.end(), func_isFive) == count_if(lstLocal.begin(), lstLocal.end(), func_isFive)
    );
    assert(bExpression); /// TRUE

    return 0;
}
