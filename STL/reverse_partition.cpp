#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

namespace STL_BOOK {
	void reverse_in_words(string &s)
	{
		reverse(s.begin(), s.end());

		for (auto it = s.begin(); true; ++it) {
			auto next = find(it, s.end(), ' ');
			reverse(it, next);
			if (next == s.end()) {
				break;
			}
			it = next;
		}
	}
	template <class Iter>
	void Reverse(Iter first, Iter last)
	{
		while (first != last) {
			--last;
			if (first == last) {
				break;
			}
			swap(*first, *last);
			++first;
		}
	}
	template<class Iter, class Unary>
	auto Partition(Iter first, Iter last, Unary p)
	{
		while (first != last && p(*first)) {
			++first;
		}

		while (first != last) {
			do {
				--last;
			} while (last != first && !p(*last));
			if (first == last) {
				break;
			}
			swap(*first, *last);
			do {
				++first;
			} while (first != last && p(*first));
		}
		return first;
	}
}

int main()
{
	string s = "My dog is very cool";
	STL_BOOK::reverse_in_words(s);
	vector<int> vLocal{ 3,1,4,1,5,9,2,6,5 };
	bool isP = is_partitioned(vLocal.begin(), vLocal.end(), [](int x) { return x % 2 == 0; }); /// false
	auto it1 = STL_BOOK::Partition(vLocal.begin(), vLocal.end(), [](int x) {
		return ((x % 2) == 0); /// 6 2 4 1 5 9 1 3 5
	});
	vector<int> vLocalTest{ 0,1,2,3,4,5,6,7,8,9,10 };
	auto it = partition(vLocalTest.begin(), vLocalTest.end(), [](int x) {
		return x % 2 == 0;	/// 0 10 2 8 4 6 5 7 3 9 1
	});
	bool isP2 = is_partitioned(vLocal.begin(), vLocal.end(), [](int x) { return x % 2 == 0; }); /// true
	vLocalTest = { 0,1,2,3,4,5,6,7,8,9,10 };
	//partition_point(vLocalTest.begin(), vLocalTest.end(), [](int x) { return x % 2 == 0; });

	system("pause");
}