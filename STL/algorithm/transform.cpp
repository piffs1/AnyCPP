#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

namespace STL_BOOK {

}

int main()
{
	using namespace std;
	vector<string> vstrInput{ "Hello", "World" };
	vector<string> vstrOutput(vstrInput.size());
	
	transform(vstrInput.begin(), vstrInput.end(), vstrOutput.begin(), [](string s) {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		return s;
	});
	
	string boris = "boris";
	transform(boris.begin(), boris.end(), boris.begin(), [](char x) {
		if (x == 'b') return 'D';
	});
	
	string str = "Cannot find or open the PDB file";
	transform(str.begin(), str.end(), str.begin(), [](char x) {
		if (x == ' ') {
			return '-';
		}
	}); /// Cannot-find-or-open-the-PDB-file"
	
	vector<int> vnLocal1{ 1,2,3,4,5 };
	transform(vnLocal1.begin(), vnLocal1.end(), vnLocal1.begin(), [](int x) {
		if (x < 3) {
			return 20;
		}
		else {
			return x;
		}
	}); /// Заметочка. Важно, чтобы функция(?) возвращала значение всегда, иначе там будет мусор
	/// vstrOutput { "HELLO", "WORLD" };


	system("pause");
}