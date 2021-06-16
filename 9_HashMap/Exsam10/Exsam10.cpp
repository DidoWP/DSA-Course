// Exsam10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, input, cPeople = 0, cProducts = 0;
	cin >> n;

	unordered_map<int, int> basket;
	unordered_set<int> id;
	
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		id.insert(input);
		basket[input]++;
	}

	unordered_set<int> ::iterator it;
	it = id.begin();
	int size = id.size();
	for(auto it = id.begin(); it < id.end(); advance(it,1))
	{
		int current = basket[*it] % 10;
		if(current > 0)
		{
			cPeople++;
			cProducts += current;
		}
		//advance(it, 1);
	}

	cout << cPeople << " " << cProducts;
}

