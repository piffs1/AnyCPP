// Example program
#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
#include <string>

/*
	Стр. 108. Разобраться!
*/

namespace STL_BOOK {
}

using namespace std;



int main()
{
	multimap<int, int> myMap;
	myMap.emplace(1, 0);
	myMap.emplace(1, 2);
	myMap.emplace(2, 4);
	assert(myMap.size() == 3);

	myMap.erase(1);
	assert(myMap.size() == 1);

	myMap.emplace(1, 0);
	myMap.emplace(1, 2);
	
	multimap<int, int> myMap1 = {
		{1,0},
		{2,4},
		{3,6},
		{3,8},
		{1,2}
	};
	
	/// Старайтесь избегать контейнеры на основе указателей (map, list, set)
	
	return 0;
}
