// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
namespace STL_BOOK {
	template<class Iterator, class T, class C>
	Iterator lower_bound(Iterator first, Iterator last, const T& value, C lessthan)
	{
		using DiffT = typename std::iterator_traits<Iterator>::difference_type;
		Iterator it;
		DiffT count = std::distance(first, last);

		while (count > 0) {
			DiffT step = count / 2;
			it = fist;
			std::advance(it, step);
			if (lessthan(*it, value)) {
				++it;
				first = it;
				count -= step + 1;
			}
			else {
				count = step;
			}
		}
		return first;
	}
}

using namespace std;

int main()
{
	vector<int> vLocal{ 1,2,2,2,2,2,3,3,3,3,4,5,6,7,8,9,10,13,16,17,100 };

	auto it = lower_bound(vLocal.begin(), vLocal.end(), 2); // vLocal[1] 
	auto jt = upper_bound(vLocal.begin(), vLocal.end(), 2); // vLocal[6]
	for (it; it != jt; ++it) { /// 2,2,2,2,2
		cout << *it << ' ';
	}

	it = lower_bound(vLocal.begin(), vLocal.end(), 12); /// Указывает на 13. Первое НЕ меньшее значение 12
	it = lower_bound(vLocal.begin(), vLocal.end(), 25); /// Указывает на 100

	it = upper_bound(vLocal.begin(), vLocal.end(), 10); /// Указывает на 13. Первое большее значение
	it = upper_bound(vLocal.begin(), vLocal.end(), 3);	/// Указывает на 4. 

	//it = lower_bound(vLocal.begin(), vLocal.end(), 2, std::less<>{});

	vector<int> vVec{ 1,3,5,8 };
	for (int value : {2, 4, 8, 9}) {
		auto it = std::lower_bound(vVec.begin(), vVec.end(), value);
		vVec.insert(it, value);
	}
	/// vVect {1, 2, 3, 4, 5, 8, 8, 9}
	for (int value : {1, 17, 3, 24, 82}) {
		auto it = std::lower_bound(vVec.begin(), vVec.end(), value);
		vVec.insert(it, value);
	}
	/// vVect {1, 1, 2, 3, 3, 4, 5, 8, 8, 9, 17, 24, 82 }
	/// При больших объемах выгоднее пользоваться методом
	auto lower = find(vVec.begin(), vVec.end(), 1); /// В данном случае find гораздо быстрее, чем lower_bound
	auto upper = find_if(lower, vVec.end(), [](int x) {return x != 1; }); /// В данном случае find_if гораздо быстрее, чем lower_bound
	assert(all_of(lower, upper, [](int x) { return x == 1; }));
	return 0;
}
