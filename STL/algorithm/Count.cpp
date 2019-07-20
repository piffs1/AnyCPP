#include <iostream>
#include <set>
#include <cassert>
#include <algorithm>

using namespace std;

namespace STL_BOOK {

}

int main()
{
    set<int> setMy{2,42,17,14,52,68,11};
    assert(setMy.count(42) == count(setMy.begin(), setMy.end(), 42));
    /// set::count имеет сложность O(log N),
    /// std::count имеет сложность O(N)
    return 0;
}
