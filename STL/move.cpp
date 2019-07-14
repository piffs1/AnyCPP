#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

/*

После этой операции элементы в перемещенном диапазоне будут 
по-прежнему содержать валидные значения соответствующего типа, 
но не обязательно те же самые, что и до перемещения.

*/

_STL_BOOK_BEGIN

template<class InputIt, class OutputIt>
OutputIt move(InputIt first1, InputIt last1, OutputIt first2)
{
	while (first1 != last1) {
		*first2++ = std::move(*first1++);
	}
	return first2;
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	
	vector<int> vNumsFrom{ 1,2,3,4,5 };
	vector<int> vNumsTo(vNumsFrom.size());
	STL_BOOK::move(vNumsFrom.begin(), vNumsFrom.end(), vNumsTo.begin());

	стоямба;
	return 0;
}

