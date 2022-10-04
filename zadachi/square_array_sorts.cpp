#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


/*
На вход подается отсортированный массив.
Необходимо вернуть массив квадратов.
Проблема таится в [-3,-2,1, 4] - > [1,4,9, 16]
Прикольная задача
*/
vector<int> square_sort(vector<int> &a)
{
	vector<int> result;
	
	if (a.empty())
	{
		return result;
	}
	result.reserve(a.size());
	int nZero_border = -1;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 0)
		{
			nZero_border = i;
			break;
		}
	}

	if (nZero_border == -1)
	{
		for (auto it = a.rbegin(); it != a.rend(); ++it)
		{
			result.push_back((*it) * (*it));
		}
	}

	int nLeft_border = nZero_border - 1;
	int nRight_border = nZero_border;
	
	while (nLeft_border >= 0 || nRight_border < a.size())
	{
		if (nLeft_border < 0)
		{
			result.push_back(a[nRight_border] * a[nRight_border]);
			nRight_border++;
		}
		else if (nRight_border >= a.size())
		{
			result.push_back(a[nLeft_border] * a[nLeft_border]);
			nLeft_border--;	
		}
		else
		{
			if (abs(a[nLeft_border]) < a[nRight_border])
			{
				result.push_back(a[nLeft_border] * a[nLeft_border]);
				nLeft_border--;
			}
			else
			{
				result.push_back(a[nRight_border] * a[nRight_border]);
				nRight_border++;
			}
		}
	}

	

	return result;
}

int main()
{
	vector<int> a = { -3, -2,-1,0,1 };
	vector<int> vResult = square_sort(a);
	for (const auto x : vResult)
	{
		cout << x << ' ';
	}
	return 0;
}