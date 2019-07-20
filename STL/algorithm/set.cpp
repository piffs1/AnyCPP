// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <functional>

namespace STL_BOOK {
}

using namespace std;



int main()
{
	set<int> _set1 = { 5,6,1,2,3,5,1,0,9 };
	assert(*_set1.begin() == 0);
	_set1.erase(0);
	assert(*_set1.begin() == 1);
	_set1.erase(_set1.begin());
	assert(*_set1.begin() == 2);
	_set1.erase(_set1.begin(), _set1.find(5)); 
	/// _set1.find(5) == find(_set1.begin(), _set1.end())
	assert(*_set1.begin() == 5);

	for (int i = 5; i < 10; i++) {
		cout << "Value " << i << " ";
		if (_set1.count(i)) { /// в случае set, count будет либо 0 либо 1
			cout << "exists ";
		}
		else {
			cout << "not exist ";
		}
		cout << "in _set1" << endl;

	}

	set<int, greater<>> _set2 = { 8,9,2,7,3,7,3,1,0,12 };
	/// minset
	auto insertPair = _set2.insert(6);

	assert(*insertPair.first == 6);
	assert(insertPair.second);

	insertPair = _set2.insert(6);

	assert(*insertPair.first == 6); 
	assert(!insertPair.second); 
	/// set<T>::insert(value) возвращает пару, в котором
	/// pair<Iterator it, bool b>. 
	/// it - возвращает позицию элемента value
	/// b - возращает БЫЛ ЛИ вставлен элемент сейчас(true) или был вставлен ранее(false)



	return 0;
}
