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
void test_merge()
{

	vector<int> vNumber{ 9,1,3,3,3,3,5,7,8 };

	vector<int> subvNumber1;
	vector<int> subvNumber2;
	for (int i = 0; i < vNumber.size() / 2; i++) {
		subvNumber1.push_back(vNumber[i]);
	}

	for (int i = vNumber.size() / 2; i < vNumber.size(); i++) {
		subvNumber2.push_back(vNumber[i]);
	}

	sort(subvNumber1.begin(), subvNumber1.end());
	sort(subvNumber2.begin(), subvNumber2.end());

	merge(subvNumber1.begin(), subvNumber1.end(), subvNumber2.begin(), subvNumber2.end(), vNumber.begin());

}
}

using namespace std;



int main()
{
	vector<int> vLocal{ 9,8,7,6,5,4,3,2,1 };
	STL_BOOK::Sort(vLocal.begin(), vLocal.end());
	STL_BOOK::test_merge();
	return 0;
}
