// Example program
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

/*
Разобраться с noexcept и конструктором перемещения!
*/

namespace STL_BOOK {
	struct Bad
	{
		int x = 0;
		Bad() = default;
		Bad(const Bad&) { puts("Copy Bad"); }
		Bad(Bad&&) { puts("Move Bad"); }
	};
	struct Good
	{
		int x = 0;
		Good() = default;
		Good(const Good&) { puts("Copy Bad"); }
		Good(Good&&) noexcept { puts("Move Bad"); }
	};

	class ImplicityGood {
		std::string x;
		Good y;
	};

	class ImplicityBad {
		std::string x;
		Bad y;
	};
}

using namespace std;



int main()
{
	STL_BOOK::ImplicityBad ID;
	
	return 0;
}
