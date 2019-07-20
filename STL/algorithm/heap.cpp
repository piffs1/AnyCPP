/* VS17 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <iterator>
#define стоямба system("pause")

namespace STL_BOOK {

}

using namespace std;

int main()
{
	setlocale(0, "");
	
	vector<int> ltMainRange{ 5, 2, 7,9,0,10,-2 };

	if (is_heap(ltMainRange.begin(), ltMainRange.end())) { /// false
		sort_heap(ltMainRange.begin(), ltMainRange.end()); /// if not heap will be assert
	}

	make_heap(ltMainRange.begin(), ltMainRange.end()); /// 10 9 7 2 0 5 -2
	cout << boolalpha << is_heap(ltMainRange.begin(), ltMainRange.end()) << endl; /// true

	if (is_heap(ltMainRange.begin(), ltMainRange.end())) {

		sort_heap(ltMainRange.begin(), ltMainRange.end()); /// -2 0 2 5 7 9 10
	}
	///						v 1							v 4
	make_heap(ltMainRange.begin(), ltMainRange.begin() + 3); /// 2 0 -2 5 7 9 10
	auto it = is_heap_until(ltMainRange.begin(), ltMainRange.end()); ///^
	if (is_heap(ltMainRange.begin(), ltMainRange.begin() + 3)) {
		sort_heap(ltMainRange.begin(), it);  /// -2 0 2 5 7 9 10
	}

	pop_heap(ltMainRange.begin(), ltMainRange.end()); /// удаляет максимальный

	стоямба;

	return 0;
}