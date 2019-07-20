// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>

namespace STL_BOOK {
	///{ 1,6,5,4,3,2,2,2 };
	namespace my {
		template <class BidirIt, class T>
		BidirIt unstable_remove(BidirIt first, BidirIt last, const T& value)
		{
			while (true) {
				first = std::find(first, last, value);
				do {
					if (first == last) {
						return last;
					}
					--last;
				} while (*last == value);
				*first = std::move(*last);
				++first;
			}
		}
	} /// end namespace my

	template<class FwdIt, class T>
	FwdIt remove(FwdIt first, FwdIt last, const T& value)
	{
		auto out = std::find(first, end, value);
		if (out != last) {
			auto in = out;
			while (++in != last) {
				if (*in == value) {

				}
				else {
					*out++ = std::move(*in);
				}
			}
		}
		return out;
	}

}

using namespace std;



int main()
{
	vector<int> vLocal{ 1,2,2,2,3,4,5,6 };
	auto it = stable_partition(vLocal.begin(), vLocal.end(), [](int n) {  return n != 2; });
	vLocal.erase(it, vLocal.end());
	/// 1,3,4,5,6
	vLocal = { 1,2,2,2,3,4,5,6 };

	it = remove(vLocal.begin(), vLocal.end(), 2);
	/// Перемещает в конец элементы. Позже необходимо выполнить erase(it,end)
	vLocal.erase(it, vLocal.end());
	/// 1,3,4,5,6

	vLocal = { 1,2,2,2,3,4,5,6 };
	vLocal.erase(lower_bound(vLocal.begin(), vLocal.end(), 2), upper_bound(vLocal.begin(), vLocal.end(), 2));

	/// 1,3,4,5,6
	vLocal = { 1,2,2,2,3,3,3,4,5,6 };
	vLocal.erase
	(
		unique(vLocal.begin(), vLocal.end()), /// Оставляет уникальные значения, только для отсортированных массивов
		vLocal.end()
	); /// тоже самое что remove, оставляет только уникальные значения
	   /// 1,2,3,4,5,6

	vLocal = { 1,2,2,2,3,4,5,6 };
	vLocal.erase(
		STL_BOOK::my::unstable_remove(vLocal.begin(), vLocal.end(), 2),
		vLocal.end()
	);
	/// 1, 6, 5, 4, 3

	return 0;
}
