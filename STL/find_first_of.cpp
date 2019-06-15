#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

namespace STL_BOOK {

template<class It, class FwdIt>
It find_first_of(It first, It last, FwdIt targetFirst, FwdIt targetLast)
{
    return find_if(first, last, [&](auto &&ebat) {
        return any_of(targetFirst, targetLast, [&](auto &&kopat) {
            return ebat == kopat;
        });
    });
}
}

int main()
{
    setlocale(0, "");
    vector<int> vLocal1{1,2,3,4,5,1,2,3,2,3,10};
    vector<int> vLocal2{8,7,5,10};

    /// find_first_of - возвращает первое вхождение любое значение из f_f_o(_,_,vLocal2.begin(), vLocal2.end())

    auto it = find_first_of(vLocal1.begin(), vLocal1.end(), vLocal2.begin(), vLocal2.end());

    /// Производим поиск в vLocal1 [begin;end) любого значения из vLocal2[begin;end)

    if (it == vLocal1.end()) {
        cout << "Значения vLocal2 не совпадают ни с одним значением vLocal1" << endl;
    }
    else {
        cout << "Элемент " << *it << " найден в vLocal1 на позиции " << distance(vLocal1.begin(), it) << endl;
    }

    return 0;
}
