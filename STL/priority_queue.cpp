// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <functional>
namespace STL_BOOK {
}

using namespace std;



int main()
{
	priority_queue<int, vector<int>> pqMaxHeap;
	priority_queue<int, vector<int>, std::greater<void>> pqMinHeap;

	for (int v : {3, 1, 4, 9, 1, 8})
	{
		pqMaxHeap.push(v);
		pqMinHeap.push(v);
	}

	assert(pqMaxHeap.top() == 9);
	assert(pqMinHeap.top() == 1);

	return 0;
}
