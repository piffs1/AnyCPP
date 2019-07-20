// Example program
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
	const int ARRAY_SIZE = 10;
	int nArray[ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	make_heap(nArray, nArray + ARRAY_SIZE); /// 10, 9, 7, 8, 5, 6, 3, 1, 4, 2
	return 0;
}