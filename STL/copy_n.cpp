#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

_STL_BOOK_BEGIN
template<class InputIt, class Size, class OutputIt>
OutputIt copy_n(InputIt first, Size count, OutputIt result)
{
	if (count > 0) {
		*result++ = *first;
		for (Size i = 1; i < count; i++) {
			*++result = *++first;
		}
	}
	return result;
}
_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	string in = "123456";
	string out;
	STL_BOOK::copy_n(in.begin(), 3, back_inserter(out));
	/// out { "123" }
	стоямба;
	return 0;
}

