// Example program
#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
#include <string>

/*
	СТР.105. Разобраться
*/


namespace STL_BOOK {
	struct MagicLess {
		using is_transparent = std::true_type;

		template <class T, class U>
		bool operator()(T&& t, U&& u) const {
			return forward<T>(t) < forward<U>(u);
		}
	};
}

using namespace std;



int main()
{
	map<string, string> _map1;
	_map1["Hello"] = "World";
	_map1["Boriska"] = "The cat";
	_map1["Hello"] = "Boris!";

	assert(_map1.size() == 2);

	assert(_map1["NULL"] == ""); /// Коварная вещь
	assert(_map1.size() == 3);
	if (_map1.find("Kotik") == _map1.end()) {
		_map1.insert(make_pair("Kotik","Antosha"));
	}
	/// ^ equals v
	_map1.emplace(make_pair("Kotik", "Boriska"));
	/// значение "Kotik" не обновится


	map<string, string, STL_BOOK::MagicLess> myMap1;
	map<string, string, less<>> myMap2;
	/// Теперь, если мы будем вызывать find("some"), то он не будет конструировать string
	return 0;
}
