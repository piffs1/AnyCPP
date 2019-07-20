/* VS17 */

#include <iostream>
#include <algorithm>
#include <list>
#include <cassert>
#include <string>
#include <iterator>
#define стоямба system("pause")

namespace STL_BOOK {

}

using namespace std;

int main()
{
	setlocale(0, "");
	
	list<int> ltMainRange	{0, 1, 2, 3 };
	list<int> ltSubRange	  { 1,    3, 4 ,6 ,8 };
	
	list<int> ltOutput;
	set_union(ltMainRange.begin(), ltMainRange.end(), 
		ltSubRange.begin(), ltSubRange.end(), back_inserter(ltOutput));
	//ltOutput {0, 1, 2, 3, 4, 6, 8}
	стоямба;

	return 0;
}