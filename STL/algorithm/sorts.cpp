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
	partial_sort(vLocal.begin(), vLocal.begin() + 3, vLocal.end() - 1);
	/// Частичная сортировка. partial_sort(it1,it2,it3)
	/// Диапазон сортировки [it1;it3]
	/// Сортируется от it1 до it2
	/// vLocal{0,1,2,7,6,6,5,9,4}
	stable_sort(vLocal.begin(), vLocal.end()); 
	/// Устойчивая сортировка
	sort(vLocal.begin(), vLocal.end());
	/// unstable
	стоямба;
	return 0;
}

