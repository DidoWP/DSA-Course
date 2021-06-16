// HotelSofiqRobbery.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, keysNeeded = 0;
	long long input;
	queue<long long> keysInRooms;
	unordered_map<int, long long> roomsMap;
	unordered_multiset<long long> curretKeys;
	cin >> n;
	
	for(int i = 1; i < n; i++)
	{
		cin >> input;
		keysInRooms.push(input);
	}
	for (int i = 1; i < n; i++)
	{
		cin >> input;
		roomsMap[i] = input;
	}

	for (int i = 1; i < n; i++)
	{
		curretKeys.insert(keysInRooms.front());
		keysInRooms.pop();

		int temp = curretKeys.count(roomsMap[i]);
		
		if(temp != 0)
		{
			curretKeys.erase(roomsMap[i]);

			if(temp > 1)
			{
				for(int j = 0; j < temp - 1; j ++)
				{
					curretKeys.insert(roomsMap[i]);
				}
			}	
		}
		else 
			keysNeeded++;	
	}

	cout << keysNeeded;
}
