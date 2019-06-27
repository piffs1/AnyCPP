// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <forward_list>

namespace STL_BOOK {
}

using namespace std;



int main()
{
	forward_list<int> flst1 = { 8,7,6,3,2,1 };
	forward_list<int> flst2 = { 0,0,0,0,0,0 };
	flst1.erase_after(find(flst1.begin(), flst1.end(), 6));
	///  { 8,7,6,2,1 };
	flst1.insert_after(find(flst1.begin(), flst1.end(), 6),3);
	///  { 8,7,6,3,2,1 };
	flst1.splice_after(flst2.begin(), flst1, flst1.begin(), flst1.end());
	return 0;
}
