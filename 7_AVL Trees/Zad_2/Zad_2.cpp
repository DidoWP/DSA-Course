// Zad_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n, input;
	set<int> subMaskSet;
	cin >> n;
	while(n > 0)
	{
		cin >> input;

		for (int submask = input; ; submask = (submask - 1) & input)
		{
			subMaskSet.insert(submask);
			if (submask == 0) break;
		}
		n--;
	}

	cout << subMaskSet.size();
    
	
}

