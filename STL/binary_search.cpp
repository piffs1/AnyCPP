#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cassert>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

_STL_BOOK_BEGIN



_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	vector<int> vLocal{ 5, 7, 4, 2, 6, 6, 1, 9, 0, 3 };
	sort(vLocal.begin(), vLocal.end());

	assert(!binary_search(vLocal.begin(), vLocal.end(), 8));
	assert(binary_search(vLocal.begin(), vLocal.end(), 7));
	assert(binary_search(vLocal.begin(), vLocal.end(), 6));
	стоямба;
	return 0;
}

