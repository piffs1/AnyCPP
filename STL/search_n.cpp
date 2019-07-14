/* VS17 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define стоямба system("pause")

using namespace std;

int main()
{
	setlocale(0, "");
	vector<int> vNumber{ 9,1,3,3,3,3,5,7,8 };
	size_t unCountElements = 2;
	int nSearchingValue = 3;
	auto it = search_n(vNumber.begin(), vNumber.end(), unCountElements, nSearchingValue);
	cout << "Найдена последовательность {3,3,3} на позиции " << distance(vNumber.begin(), it) << endl;
	/// 2
	nSearchingValue = 5;
	it = search_n(vNumber.begin(), vNumber.end(), unCountElements, nSearchingValue);
	assert(it == vNumber.end());
	стоямба;

	return 0;
}