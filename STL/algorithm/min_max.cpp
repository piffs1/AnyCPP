#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace STL_BOOK {

}

int main()
{
	int nFirst = 5;
	int nSecond = 6;
	cout << max(nFirst, nSecond) << endl; /// 6
	cout << min(nFirst, nSecond) << endl; /// 6
	vector<int> vFirst{ 1,2,3,4,5,6 };
	auto it = max_element(vFirst.begin(), vFirst.end()); /// 6
	auto jt = min_element(vFirst.begin(), vFirst.end()); /// 1
	pair<int, int> _pair = minmax(nFirst, nSecond);
	assert(_pair.first == nFirst);
	assert(_pair.second == nSecond);
	_pair = minmax(nSecond, nFirst);
	assert(_pair.first == nFirst);
	assert(_pair.second == nSecond);

	auto pair_its = minmax_element(vFirst.begin(), vFirst.end());
	assert(*pair_its.first = nFirst);
	assert(*pair_its.second == nSecond);
	return 0;
}
