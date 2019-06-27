// Example program
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
namespace STL_BOOK {
	template<class Iterator>
	void my_rotate(Iterator first, Iterator mid, Iterator last)
	{
		std::reverse(first, last);
		std::reverse(first, mid);
		std::reverse(mid, last);
	}
	template<class Iterator>
	Iterator Rotate(Iterator first, Iterator mid, Iterator last)
	{
		auto result = first + (last - mid);
		std::reverse(first, last);
		std::reverse(first, result);
		std::reverse(result, last);
		return result;
	}
}

using namespace std;



int main()
{
	vector<int> vnLocal{ 1,2,3,4,5,6,7,8,9 };
	rotate(vnLocal.begin(), vnLocal.begin() + (vnLocal.size() / 2), vnLocal.end()); /// 5,6,7,8,9,1,2,3,4
	STL_BOOK::my_rotate(vnLocal.begin(), vnLocal.begin() + (vnLocal.size() / 2), vnLocal.end()); /// 1,2,3,...,9
	
	vector<int> vnTest{ 10, 20, 30 };
	vector<vector<int>> vvResult{ vnTest };
	while (next_permutation(vnTest.begin(), vnTest.end())) {
		vvResult.push_back(vnTest);
	}
	/*
	assert(vvResult == {
		{ 10, 20, 30 },
		{ 10, 30, 20 },
		{ 20, 10, 30 },
		{ 20, 30, 10 },
		{ 30, 10, 20 },
		{ 30, 20, 10 },
	});
	*/
	system("pause");
	return 0;
}
