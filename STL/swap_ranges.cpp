#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cassert>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

/*

*/

_STL_BOOK_BEGIN

template<class FwdIt1, class FwdIt2>
FwdIt1 swap_ranges(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2)
{
	while (first1 != last1) {
		std::iter_swap(first1++, first2++);
	}
	return first2;
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	vector<int> vLocal1{ 1,2,3,4 };
	vector<int> vLocal2(vLocal1.size(), 0);

	auto it = STL_BOOK::swap_ranges(vLocal1.begin(), vLocal1.begin() + 2, vLocal2.begin());
	/// vLocal2 {1,2,0,0}
	/// vLocal1 {0,0,3,4}
	стоямба;
	return 0;
}

