#include <algorithm>
#include <iostream>
#include <vector>

#define стоямба system("pause")

namespace STL_BOOK {
	template<class FwdIt, class BinaryPredicate>
	FwdIt adjacent_find(FwdIt first, FwdIt last, BinaryPredicate p)
	{
		if (first == last) {
			return last;
		}

		FwdIt next = std::next(first);

		for (; next != last; ++next, ++first) {
			if (p(*first, *next)) {
				return first;
			}
		}

		return last;
	}

	template<class FwdIt>
	FwdIt adjacent_find(FwdIt first, FwdIt last)
	{
		if (first == last) {
			return last;
		}

		FwdIt next = std::next(first);

		for (; next != last; ++next, ++first) {
			if (first, *next) {
				return first;
			}
		}

		return last;
	}
}

using namespace std;


int main()
{
	setlocale(0, "");
	vector<int> vNumbers1{ 2,2,3,3,8,1,2,1,0,0,8,5,1 };

	auto it = vNumbers1.begin();

	while (true) {
		it = adjacent_find(it, vNumbers1.end());
		if (it == vNumbers1.end()) {
			break;
		}
		cout << "Смежный повторяющийся элемент на позиции " << distance(vNumbers1.begin(), it) << endl;
		/// 0 2 8
		++it;
		
	}

	стоямба;
	return 0;
}

