// Example program
#include "stdafx.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>

namespace STL_BOOK {
	std::array<int,3> CrossProduct(const std::array<int, 3> &a, const std::array<int, 3> &b)
	{
		return { {
				a[0] * b[0],
				a[1] * b[1],
				a[2] * b[2],
		} };
	}
}

using namespace std;



int main()
{
	array<int, 5> STLarr = { {1,2,3,4,4} };
	array<int, 5> STLarr2 = { {0} };
	STLarr2 = STLarr; /// Линейное время. copy
	STLarr2.assign(0);
	std::swap(STLarr2, STLarr); /// Меняет данные, но не адреса
	
	int arr[] = { 1,2,3,4,4 };
	int arr2[sizeof(arr)/sizeof(int)] = { 0 };
	
	std::swap(arr, arr2); /// Меняет данные, но не адреса
	
	return 0;
}
