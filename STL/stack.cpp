// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>
namespace STL_BOOK {
}

using namespace std;



int main()
{
	//stack<int, vector<int>> _stack;
	stack<int> _stack1;
	stack<int> _stack2;
	_stack1.push(3); _stack1.push(4); _stack1.push(6);
	_stack2.push(2); _stack2.push(6); _stack2.push(8);
	
	assert(_stack1 > _stack2); 
	/// Сравнивает элементы сверху вниз Т.е. 
	/// Сначала 3 и 2, потом 4 и 6, потом 6 и 8
	_stack1 = _stack2;
	assert(_stack1 == _stack2);
	assert(&_stack1 != &_stack2);
	return 0;
}
