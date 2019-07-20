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

template <class FwdIt, class Value>
void replace(FwdIt first, FwdIt last, const Value& old_value, const Value& new_value)
{
	while (first != last) {
		if (*first == old_value) {
			*first = new_value;
		}
		first++;
	}
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	vector<int> vNums{ 1,2,3,4,5,6,7,8,9 };
	replace(vNums.begin(), vNums.end(), 5, 55);
	replace_if(vNums.begin(), vNums.end(), [](int &x) {
		return x == 55 ? true : false;
	}, 5);
	string strSource = "Boriska wonderful cat";
	STL_BOOK::replace(strSource.begin(), strSource.end(), ' ', '_');
	assert(strSource == "Boriska_wonderful_cat");
	replace_if(strSource.begin(), strSource.end(), [](char &x) {
		return x == '_';
	}, ' ');
	assert(strSource == "Boriska wonderful cat");
	стоямба;
	return 0;
}

