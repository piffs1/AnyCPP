#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>



namespace STL_BOOK {
	template<class FwdIt1, class FwdIt2, class T>
	T inner_product(FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, T value)
	{
		for (; first1 != last1; ++first1, ++first2) {
			value += *first1 * *first2;
		}
		return value;
	}
}
using namespace std;

int main()
{
	vector<int> vLocal{ 1,2,3,4,5 };
	vector<int> vLocal2{ 1,2,3,5,8 };
	if (vLocal.size() == vLocal2.size()) {
		assert(
			inner_product(vLocal.begin(), vLocal.end(), vLocal2.begin(), 0) 
			== 
			STL_BOOK::inner_product(vLocal.begin(), vLocal.end(), vLocal2.begin(), 0)
			); /// 74. inner_product ищет скалярное произведение двух векторов.
			   /// Проще говоря итеративное перемножение элементов. 
	}

	return 0;
}
