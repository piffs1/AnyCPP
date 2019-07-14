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
	is_sorted_until() ищет уже длину отсортированной коллекции вначале
*/

_STL_BOOK_BEGIN

void test_is_sorted()
{
	std::vector<int> vLocal1{ 1,2,3,4,5,6 };
	assert(is_sorted(vLocal1.begin(), vLocal1.end()));
	std::sort(vLocal1.begin(), vLocal1.end(), [](int &x, int &y) {
		return y < x;
	});
	/// vLocal1{6,5,4,3,2,1}
	assert(!is_sorted(vLocal1.begin(), vLocal1.end()));
	assert(is_sorted(vLocal1.begin(), vLocal1.end(), [](int &x, int &y) {
		return y < x;
	}));
}

void test_is_sorted_until()
{
	std::vector<int> vLocal{ 1,2,3,4,1,2,3 };
	assert(*is_sorted_until(vLocal.begin(), vLocal.end()) == 1);
	vLocal = { 7,2,1,2,7,9,10 };
	assert(*is_sorted_until(vLocal.begin(), vLocal.end()) == 2);
	vLocal = { 9,8,7,6,5,4,3,2,1 };
	assert(vLocal.end() == is_sorted_until(vLocal.begin(), vLocal.end(), [](int &x, int &y) {
		return y < x;
	}));
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	STL_BOOK::test_is_sorted();
	STL_BOOK::test_is_sorted_until();
	стоямба;
	return 0;
}

