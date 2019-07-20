/* VS17 */

#include <iostream>
#include <algorithm>
#include <list>
#include <cassert>
#include <string>
#include <iterator>
#define стоямба system("pause")

namespace STL_BOOK {
	template<class FwdIt1, class FwdIt2>
	bool includes(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2)
	{
		for (; first2 != last2; ++first1)
		{
			if (first1 == last1 || *first2 < *first1)
				return false;
			if (!(*first1 < *first2))
				++first2;
		}
		return true;
	}
}

using namespace std;

int main()
{
	setlocale(0, "");
	
	list<int> ltMainRange		{ 1,2,3,4,5 };
	list<int> ltSubRangeValid	  { 2,3,4};
	list<int> ltSubRangeValid2{ 1,  3,4 };
	cout << boolalpha << includes(ltMainRange.begin(), ltMainRange.end(), ltSubRangeValid.begin(), ltSubRangeValid.end()) << endl; /// true
	cout << boolalpha << includes(ltSubRangeValid.begin(), ltSubRangeValid.end(), ltMainRange.begin(), ltMainRange.end()) << endl; /// false
	cout << boolalpha << includes(ltMainRange.begin(), ltMainRange.end(), ltSubRangeValid2.begin(), ltSubRangeValid2.end()) << endl; /// true

	стоямба;

	return 0;
}