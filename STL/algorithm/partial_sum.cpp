#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>


namespace STL_BOOK {
}
using namespace std;

int main()
{
	vector<int> vLocal{ 1,2,3,4,5 };
	vector<int> vOutput;
	partial_sum(vLocal.begin(), vLocal.end(), back_inserter(vOutput)); 
	/// vOutput{1, 3, 6, 10, 15};
	vOutput.erase(vOutput.begin(), vOutput.end());

	partial_sum(vLocal.begin(), vLocal.end(), back_inserter(vOutput), [](int& nF, const int& nS){
		return nF *= nS;
	});
	/// vOutput{1, 2, 6, 24, 120}
	return 0;
}
