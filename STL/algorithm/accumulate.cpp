#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>



namespace STL_BOOK {
	template<class FwdIt, class T, class Func>
	T accumulate(FwdIt first, FwdIt last, T value, Func f)
	{
		for (; first != last; ++first) {
			value = f(value, *first);
		}
		return value;
	}
}
using namespace std;
const int Multiply(const int &x, const int &y)
{
	return x * y;
}

const string StrSumOdd(string& a_string, const int& a_n)
{
	return (a_n & 1) ? a_string += "O" : a_string += "N";
}

int main()
{
	
	vector<int> vLocal{ 1,0,-1,3,12,-16,7 };
	int nSumValue = accumulate(vLocal.begin(), vLocal.end(), 0); /// 6
	
	vector<int> vLocal1{ 1,2,3,4 ,-5};
	int nMultiplyValue = accumulate(vLocal1.begin(), vLocal1.end(), 1, Multiply); /// -120
	string strResult = accumulate(vLocal1.begin(), vLocal1.end(), string(), StrSumOdd); /// ONONO
	

	return 0;
}
