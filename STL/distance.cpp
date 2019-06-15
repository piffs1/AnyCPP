#include <iostream>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

namespace STL_BOOK {

template<typename Iterator>
int distance(Iterator begin, Iterator end)
{
    int nSum = 0;
    for (Iterator it = begin; it != end; ++it) {
        nSum++;
    }
    return nSum;
}

template<>
int distance(int* begin, int* end)
{
    return end - begin;
}

}
int main()
{
    vector<int> vLocal;
    vector<int> vLocal1{3,4};
    list<int> lstLocal{1,2,3,4,5,6};

    bool bExpression = STL_BOOK::distance(vLocal.begin(),vLocal.end()) == distance(vLocal.begin(),vLocal.end());
    assert(bExpression); /// TRUE

    bExpression = STL_BOOK::distance(vLocal1.begin(),vLocal1.end()) == distance(vLocal1.begin(),vLocal1.end());
    assert(bExpression); /// TRUE

    bExpression = STL_BOOK::distance(lstLocal.begin(),lstLocal.end()) == distance(lstLocal.begin(),lstLocal.end());
    assert(bExpression); /// TRUE

    return 0;
}
