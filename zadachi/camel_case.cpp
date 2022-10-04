/// Vectors intersection


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string CamelCase(const string& a_str)
{
	string result;
	result.reserve(a_str.size());
	bool bIsSpace = true;
	for (int i = 0; i < a_str.size(); i++) 
	{
		if (a_str[i] == ' ')
		{
			bIsSpace = true;
			continue;
		}
		if (isalpha(a_str[i]))
		{
			if (bIsSpace)
			{
				result += toupper(a_str[i]);
				bIsSpace = false;
			}
			else
			{
				result += a_str[i];
			}
		}
	}
	return result;
}


int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << CamelCase(str) << endl;
	}
}