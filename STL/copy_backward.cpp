#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

_STL_BOOK_BEGIN

template<class BiDirIt1, class BiDirIt2>
BiDirIt2 copy_backward(BiDirIt1 first1, BiDirIt1 last1, BiDirIt2 last2)
{
	while (first1 != last1) {
		*(--last2) = *(--last1);
	}
	return last2;
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	vector<int> vFrom;
	for (int i = 0; i < 5; i++) {
		vFrom.push_back(i);
	}

	vector<int> vTo(7);

	STL_BOOK::copy_backward(vFrom.begin(), vFrom.end(), vTo.end());
	/// vTo {0,0,1,2,3,4}
	стоямба;
	return 0;
}

