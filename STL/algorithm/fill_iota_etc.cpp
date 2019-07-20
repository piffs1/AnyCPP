#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
namespace STL_BOOK {
	template<class Iterator, class Value>
	void fill(Iterator first, Iterator last, Value value)
	{
		while (first != last) {
			*first = value;
			++first;
		}
	}
	template<class Iterator, class Value>
	void iota(Iterator first, Iterator last, Value value)
	{
		while (first != last) {
			*first = value++;
			++first;
		}
	}
	template<class Iterator, class Generator>
	void generate(Iterator first, Iterator last, Generator generator)
	{
		while (first != last) {
			*first = generator();
			++first;
		}
	}

	
}

int main()
{
	using namespace std;
	vector<int> vLocal(6);
	fill(vLocal.begin(), vLocal.end(), 0); /// vLocal{0,0,0,0,0,0}
	iota(vLocal.begin(), vLocal.end(), 0); /// vLocal{0,1,2,3,4,5}
	vector<string> vLocal2(6);
	generate(vLocal2.begin(), vLocal2.end(), [i = 0]() mutable{
		return ++i % 2 ? "Hello" : "World";
	});
	system("pause");
}