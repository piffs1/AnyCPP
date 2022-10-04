#include <iostream> 
 
using namespace std; 
 
//wave("hello") = > {"Hello", "hEllo", "heLlo", "helLo", "hellO"}

vector<string> wave(const std::string &str)
{
	vector<string> strResult;
	strResult.reserve(str.size());

	string strTemp = str;

	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(strTemp[i]))
		{
			strTemp[i] = toupper(strTemp[i]);
			strResult.push_back(strTemp);
			strTemp[i] = tolower(strTemp[i]);
		}
	}
	return strResult;
}
 
int main(){ 
 
	return 0; 
} 
