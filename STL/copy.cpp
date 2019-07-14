#include <algorithm>
#include <cassert>ц
#include <iostream>
#include <vector>
using namespace std;

namespace STL_BOOK {

template<class Iterator>
Iterator copy(Iterator first, Iterator last, Iterator result)
{
    while(first != last) {
        *result++ = *first++;
    }
    return result;
}

template<class Iterator, class Predicate>
Iterator copy_if(Iterator first, Iterator last, Iterator result, Predicate pred)
{
    while(first != last) {
        if (pred(*first)){
            *result++ = *first;
        }
        first++;
    }
    return result;
}

}

int main()
{
    vector<int> vTestCopyFrom{1,2,3,4,5,6};
    vector<int> vTestCopyTo(vTestCopyFrom.size());
    vector<int> vTestCopy_ifTo(vTestCopyFrom.size());

    auto jt = copy(vTestCopyFrom.begin(), vTestCopyFrom.end(), vTestCopyTo.begin());
    /// Размер результирующего контейнера должен быть определен до вызова алгоритма
    for (auto it = vTestCopyTo.begin(); it != vTestCopyTo.end(); ++it) {
        cout << *it << endl;
    }

    assert(jt == vTestCopyTo.end());

    auto jtag = copy_if(vTestCopyFrom.begin(), vTestCopyFrom.end(), vTestCopy_ifTo.begin(), [](int x){
        return (x > 3);
    });

    vTestCopy_ifTo.resize(distance(jtag, vTestCopy_ifTo.end()));

    for (auto it = vTestCopy_ifTo.begin(); it != vTestCopy_ifTo.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
