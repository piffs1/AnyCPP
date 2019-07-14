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
void iter_swap(FwdIt1 it, FwdIt2 jt)
{
	std::swap(*it, *jt);
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	
	vector<int> vLocal1{ 1,2 };
	vector<int> vLocal2{ 3,4 };
	STL_BOOK::iter_swap(vLocal1.begin(), vLocal2.begin());
	/// vLocal1{3,2}
	/// vLocal2{1,4}
	
	стоямба;
	return 0;
}

