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
	system("pause");
	return 0;
}
