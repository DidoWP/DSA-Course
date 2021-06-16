// GeneticEngineering.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int howMuchFood(unsigned long long left, unsigned long long right,unsigned long long);

int main()
{
	
    long P, N;
	cin >> P >> N;
	vector<unsigned long long> numbersN;
		
	for(long i=0; i<N; i++)
	{
		unsigned long long temp;
		cin >> temp;
		numbersN.push_back(temp);
	}

	unsigned long long lenghtAll = pow(3, P) - 1;
	
	for(long i=0; i<N; i++)
	{
		printf("%d \n", howMuchFood( 0, lenghtAll, numbersN[i]));
	}
}

int howMuchFood(unsigned long long left, unsigned long long right,unsigned long long searchingNum)
{
	int counter = 0;
	while (right >= left)
	{
		counter++;
		unsigned long long mid1 = left + (right - left) / 3;
		unsigned long long mid2 = right - (right - left) / 3;

		if (mid1 + 1 < searchingNum && searchingNum < mid2 + 1)
			return counter;

		if (left == mid1 && right == mid2)
		{
			if (searchingNum == left + 1) return counter + 1;
			if (searchingNum == left + 2) return counter;
			if (searchingNum == right + 1) return counter + 1;
		}

		if (searchingNum <= mid1 + 1)
		{
			right = mid1;
		}
		else if (searchingNum >= mid2 + 1)
		{
			left = mid2;
		}
	}
	return counter;
}
