// Example program
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace STL_BOOK {
	template<class RandomIterator>
	void Sort(RandomIterator first, RandomIterator last)
	{
		auto n = std::distance(first, last);
		if (n >= 2) {
			auto mid = first + n / 2;
			std::sort(first, mid);
			std::sort(mid, last);
			std::inplace_merge(first, mid, last);
		}
	}
	template<class RandomIterator, class Predicate>
	void Sort(RandomIterator first, RandomIterator last, Predicate pred)
	{
		auto n = std::distance(last, first);
		if (n >= 2) {
			auto mid = first + n / 2;
			std::sort(first, mid, pred);
			std::sort(mid, last, pred);
			std::inplace_merge(first, mid, last); 
		}
	}
}

using namespace std;



int main()
{
	vector<int> vLocal{ 9,8,7,6,5,4,3,2,1 };
	STL_BOOK::Sort(vLocal.begin(), vLocal.end());
	return 0;
}
