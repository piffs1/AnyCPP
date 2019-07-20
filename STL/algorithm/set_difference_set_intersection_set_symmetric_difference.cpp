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
	
	list<int> ltMainRange		{ 1,2,3,4,5 };
	list<int> ltSubRange{ 1,  3,4, 6 };
	
	list<int> ltOutput;
	set_difference(ltMainRange.begin(), ltMainRange.end(), 
		ltSubRange.begin(), ltSubRange.end(), back_inserter(ltOutput));

	// ltOutput {2,5}. Возвращает разницу только для первого контейнера со вторым
	ltOutput.erase(ltOutput.begin(), ltOutput.end());
	set_intersection(ltMainRange.begin(), ltMainRange.end(),
		ltSubRange.begin(), ltSubRange.end(), back_inserter(ltOutput));

	// ltOutput {1, 3, 4}. 
	ltOutput.erase(ltOutput.begin(), ltOutput.end());

	set_symmetric_difference(ltMainRange.begin(), ltMainRange.end(),
		ltSubRange.begin(), ltSubRange.end(), back_inserter(ltOutput));
	// ltOutput {2, 5, 6}. Возвращает разницу для двух контейнеров
	стоямба;

	return 0;
}