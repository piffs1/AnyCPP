// Example program
#include "stdafx.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <cassert>
#include <string>
namespace STL_BOOK {
}

using namespace std;

struct C {
	int a;
	int b;
	~C() { cout << "I'm free!!!" << endl; }
};

int main()
{
	shared_ptr<C> sptr0;
	shared_ptr<C> sptr1(new C);
	shared_ptr<C> sptr2 = sptr1;
	shared_ptr<C> sptr3 = sptr2;
	cout << sptr1.use_count() << endl; /// 3

	sptr1.reset(); /// or sptr1 = nullptr;

	cout << sptr2.use_count() << endl; /// 2

	sptr1 = sptr2 = sptr3 = nullptr; /// ~C() called


	return 0;
}
