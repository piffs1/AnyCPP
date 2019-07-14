#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

_STL_BOOK_BEGIN

template<class BiDirItIn, class BiDirItOut>
BiDirItOut move_backward(BiDirItIn first1, BiDirItIn last1, BiDirItOut last2)
{
	while (first1 != last1) {
		*(--last2) = std::move(*(--last1));
	}
	return last2;
}
_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	const int VFROM_SIZE = 10;
	const int VTO_SIZE = VFROM_SIZE + 5;
	vector<int> vFrom;
	for (int i = 0; i < VFROM_SIZE; i++) {
		vFrom.push_back(i);
	}
	vector<int> vTo(VTO_SIZE);
	move_backward(vFrom.begin(), vFrom.end(), vTo.end());
	/// vTo {0,0,0,0,0,1,2,3,4,5,6,7,8,9}
	стоямба;
	return 0;
}

