#include <iostream>
#include <algorithm>
#include <vector>



namespace STL_BOOK {

}

using namespace std;

int main()
{
	vector<int> vNumbers{1,2,3,3,3,4,5,6};
    vector<int> vSearch{3,3};
    auto ffo = find_first_of(vNumbers.begin(), vNumbers.end(), vSearch.begin(), vSearch.end());
    /// Итератор указывает на первое вхождение
    auto fe = find_end(vNumbers.begin(), vNumbers.end(), vSearch.begin(), vSearch.end());
    /// Итератор указывает на последнее вхождение в диапазон [vSearch.begin(), vSearch.end())

    for (ffo; ffo != vNumbers.end(); ++ffo) {
        cout << *ffo << ' '; /// 3 3 3 4 5 6
    }
    
    cout << endl;

    for (fe; fe != vNumbers.end(); ++fe) {
        cout << *fe << ' '; /// 3 3 4 5 6
    }

	return 0;
}
