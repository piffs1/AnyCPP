#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
namespace STL_BOOK {
}

using namespace std;



int main()
{
	vector<int> vN = { 1, 2 };
	vN.insert(vN.begin() + 1, 3); /// Вставить тройку
	vN.insert(vN.begin() + 2, 3, 4); /// Вставить три четверки
	/// 1, 3, 4, 4, 4, 2
	vN.insert(vN.end(), vN.begin(), vN.end()); /// Вставить в конец вектора вектор
	vN.insert(vN.begin(), { 0 });
	return 0;
}
