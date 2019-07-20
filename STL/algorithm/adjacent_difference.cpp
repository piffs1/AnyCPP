#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>


namespace STL_BOOK {
	/*

	*(d_first)   = *first;
	*(d_first+1) = (*first+1) - *(first);
	*(d_first+2) = (*first+2) - *(first+1);
	*(d_first+3) = (*first+3) - *(first+2);

	*/
}
using namespace std;

int main()
{
	vector<int> vLocal{ 1,2,3,4,5 };
	vector<int> vOutput;
	adjacent_difference(vLocal.begin(), vLocal.end(), vLocal.begin()); /// 1 1 1 1 1


	vector<int> vFibbonachi(10); /// найти 10 элементов фиббоначи
	fill(vFibbonachi.begin(), vFibbonachi.end(), 1);
	adjacent_difference(vFibbonachi.begin(), vFibbonachi.end() - 1, vFibbonachi.begin() + 1, [](const int &x,const int &y) {
		return x + y;
	});
	
	return 0;
}
