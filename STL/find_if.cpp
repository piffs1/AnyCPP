#include <iostream>
#include <set>
#include <cassert>
#include <algorithm>
#define END_NAMESPACE }
using namespace std;

namespace STL_BOOK {
template<class Iterator, class Predicate>
Iterator find_if(Iterator first, Iterator last, Predicate pred)
{
    for(; first != last; ++first) {
        if(pred(*first)) {
            return first;
            /// ���������� �� �������� �����.
            /// ��� ������ ������ ������, ����� �� ����������.
        }
    }
    return last;
}
END_NAMESPACE

int main()
{
    setlocale(0, "");
    vector<int> vLocal{1,2,3,4,5,6,5,7,8};

    auto it = find(vLocal.begin(), vLocal.end(), 5);
    if (it != vLocal.end()) {
        cout << "������ ��������� : " << distance(vLocal.begin(), it) << endl; /// 4
    }

    it = find_if(vLocal.begin(), vLocal.end(), [](int x){
        return (x == 5);
    });

    if (it != vLocal.end()) {
        cout << "������ ��������� : " << distance(vLocal.begin(), it) << endl; /// 4
    }

    it = find_if_not(vLocal.begin(), vLocal.end(), [](int x){
        return (x==5);
    });

    if (it != vLocal.end()) {
        cout << "������ ��������� : " << distance(vLocal.begin(), it) << ". �������� " << *it << endl; /// �.�. 0. � 1
    }

    return 0;
}
