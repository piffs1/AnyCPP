#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

/*

remove_copy удаляет элементы или нет ? 
- Копирует без элемента Value. Не удаляет
*/

_STL_BOOK_BEGIN

template<class InputIt, class OutputIt, class Value>
OutputIt remove_copy(InputIt first1, InputIt last1, OutputIt first2, const Value &value)
{
	while (first1 != last1) {
		if (!(*first1 == value)) {
			*first2++ = *first1;
		}
		first1++;
	}
	return first2;
}

_STL_BOOK_END

using namespace std;


int main()
{
	setlocale(0, "");
	vector<int> vFrom{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> vTo(vFrom.size());

	STL_BOOK::remove_copy(vFrom.begin(), vFrom.end(), vTo.begin(), 4);
	/*
	copy_if(vFrom.begin(), vFrom.end(), vTo.begin(), [](int &x) {
		if (x == 4) {
			return false;
		}
		return true;
	});
	
	equals ???

	*/
	
	string strSource = "Text with spaces";
	remove_copy(strSource.begin(), strSource.end(), ostream_iterator<char>(cout), ' '); cout << endl;
	/// Textwithspaces
	
	стоямба;
	return 0;
}

