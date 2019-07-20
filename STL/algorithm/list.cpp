// Example program
#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>
#include <string>

namespace STL_BOOK {
}

using namespace std;



int main()
{
	list<int> lstN1{ 1,2,3,4,5,6,7,8 };
	list<int> lstN2{ 0 };
	lstN1.splice(lstN1.begin(), lstN2);
	/// lstN1 {0,1,2,3,4,5,6,7,8}
	/// lstN2 {}

	lstN1.reverse();
	/// lstN1{ 8,7,6,5,4,3,2,1,0 }

	lstN1.remove(5); /// Стирает и удаляет сразу
	/// lstN1{ 8,7,6,4,3,2,1,0 }
	lstN1.remove_if([](auto a_value) {
		return a_value > 3;
	});
	/// lstN1{3,2,1,0}
	/// list<T>::unique equals unique(...)
	
	list<int> lstTest1 = { 7,8,1,2,3,9,0,12,42 };
	auto begin = next(lstTest1.begin(), 2);
	auto end = next(lstTest1.begin(), 7);
	list<int> lstSub1;

	lstSub1.splice(lstSub1.begin(), lstTest1, begin, end);
	lstSub1.sort();
	lstTest1.splice(end, lstSub1); 
	/// splice инсертит перед end
	/// При этом стоит заметить, что мы добавляем по итератору end.
	/// Потому что у листа при удалении/вставке элемента итераторы не меняют значения


	return 0;
}
