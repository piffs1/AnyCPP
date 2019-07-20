#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define _STL_BOOK_BEGIN namespace STL_BOOK {
#define _STL_BOOK_END }

#define стоямба system("pause")

/*
	Мюсли. Тот же find только целого диапазона. Удобен для словечек
*/

_STL_BOOK_BEGIN

template<class ForwardIt1, class ForwardIt2>
ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
	ForwardIt2 s_first, ForwardIt2 s_last)
{
	for (; ; ++first) {
		ForwardIt1 it = first;
		for (ForwardIt2 s_it = s_first; ; ++it, ++s_it) {
			if (s_it == s_last) {
				return first;
			}
			if (it == last) {
				return last;
			}
			if (!(*it == *s_it)) {
				break;
			}
		}
	}
}

_STL_BOOK_END

using namespace std;
template<class Container>
bool in_string(const Container &a_container, const string &a_find)
{
	return STL_BOOK::search(a_container.begin(), a_container.end(), a_find.begin(), a_find.end()) != a_container.end();
}

int main()
{
	setlocale(0, "");
	string strSource = "Борис замечательный котенок";
	
	cout << boolalpha << in_string(strSource, "Котенок") << endl; 
	/// false
	cout << boolalpha << in_string(strSource, "котенок") << endl;
	/// true
	cout << boolalpha << in_string(strSource, "замечательный") << endl;
	/// true

	string str = "Сегодня замечательный день денечек";
	string strFind = "ден";
	auto it = STL_BOOK::search(str.begin(), str.end(), strFind.begin(), strFind.end());
	/// День денечек
	it = str.begin();
	while (true) {
		it = search(it, str.end(), strFind.begin(), strFind.end());
		if (it == str.end()) {
			break;
		}
		cout << "Слово" << strFind << "найдено на позиции " << distance(str.begin(), it) << endl;
		/// 22, 27
		++it;
	}

	стоямба;
	return 0;
}

