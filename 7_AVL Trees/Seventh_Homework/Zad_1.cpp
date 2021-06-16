// Seventh_Homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;
	long x;
	string input;
	set<long> mySet;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> input;
	
		if(input == "add")
		{
			cin >> x;
			mySet.insert(x);
		}
		else if(input == "del")
		{
			cin >> x;
			mySet.erase(x);
		}
		else if(input == "inorder")
		{
			for(auto num : mySet)
			{
				cout << num << " ";
			}
			cout << endl;
		}
	}

}
