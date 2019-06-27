// Example program
#include "stdafx.h"
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

/*

		Стр.118

*/

namespace STL_BOOK {
}

using namespace std;
template<typename T>
constexpr size_t tuple_size(T&&)
{
	return tuple_size<remove_reference<T>>;
}

int main()

{
	tuple<int, int, int, int, int, int, int, int, int> tpl = make_tuple(1, 2, 3, 4, 0, 5, 67, 78, 0);
	setlocale(0, "");
	string str;
	int n;

	tie(str, n) = make_tuple("Hello", 1); /// Присваивает str = "Hello" n = 1

	using Author = pair<string, string>;
	vector<Author> authors = {
		{"Федор","Достоевский"},
		{"Лев","Толстой"},
		{"Александр", "Пушкин"},
		{"Сергей", "Есенин"},
		{"Василий", "Есенин"},
		{"Сергей", "Пушкин"},
		{"Антон", "Достоевский"}
	};

	sort(authors.begin(), authors.end(), [](auto &&a, auto &&b) {
		return tie(a.second, a.first) < tie(b.second, b.first);
		/// compares a.second < b.second
		/// after a.first < b.first
	});

	using Authors_SNL = tuple<string, string, string>;
	vector<Authors_SNL> authorsSNL = {
		{"Иванов", "Иван", "Иванович"},
		{"Иванов", "Иван", "Сергеевич"},
		{"Иванов", "Иван", "Александрович"},
		{"Сергеев", "Иван", "Александрович"},
		{"Александров", "Сергей", "Иванович"},
		{"Александров","Антон","Владимирович"}
	};
	
	sort(authorsSNL.begin(), authorsSNL.end(), [](Authors_SNL a, Authors_SNL b) {
		return tie(get<0>(a), get<1>(a), get<2>(a)) < tie(get<0>(b), get<1>(b), get<2>(b));
	});


	return 0;
}
