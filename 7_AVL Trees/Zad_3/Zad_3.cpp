// Zad_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//int getMinXOR(int num, vector<int> vec)
//{
//	int min = INT32_MAX;
//	int temp;
//
//	sort(vec.begin(), vec.end());
//	
//	for(unsigned int i = 0; i < vec.size() - 1; i++)
//	{
//		temp = vec[i] ^ vec[i + 1];
//		if (temp < min && temp != 0)
//			min = temp;
//	}
//
//	if (vec.size() == 1)
//		min = vec[0] ^ num;
//
//	return min;
//}

int main()
{
    int q, input, min;
	set<int> s;
	vector<int> result;

	s.insert(0);
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		cin >> input;
		if(i == 0)
		{
			min = 0 ^ input;
			result.push_back(min);
			s.insert(input);
		}
		else
		{
			s.insert(input);
			auto inputLower_b = s.lower_bound(input);
			auto inputUpper_b = s.upper_bound(input);

			advance(inputLower_b, -1);

			int minBound;
			int lowerB = *inputLower_b ^ input;
			int upperB = *inputUpper_b ^ input;

			if (lowerB < upperB)
			{
				if (lowerB != 0)
					minBound = lowerB;
				else
					minBound = upperB;
			}
			else
				minBound = upperB;

			if (minBound <= result[i - 1])
			{
				result.push_back(minBound);
			}
				
			else
			{
				result.push_back(result[i - 1]);
			}
				
		}
		
	}

	for (auto v : result)
		cout << v << endl;
}
