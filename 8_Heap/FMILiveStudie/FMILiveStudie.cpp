// FMILiveStudie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> pi;

//struct myComp { 
//    constexpr bool operator()( 
//        pair<int, int> const& a, 
//        pair<int, int> const& b) 
//        const noexcept 
//    { 
//        return a.second < b.second; 
//    } 
//};
//
//priority_queue<pi, vector<pi>, myComp> compareBySecond;
//
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int n, br = 0;
	cin >> n;

	priority_queue<pi, vector<pi>, greater<pi>> minHeap;
	vector<pair<int, int>> rooms;

	pair<int, int> nullPair;
	nullPair.first = 0;
	nullPair.second = 0;
	
	for(int i=0; i<n; i++)
	{
		rooms.push_back(nullPair);
	}
	
	pair<int, int> temp;
	for(int i=0; i<n; i++)
	{
		cin >> temp.first;
		cin >> temp.second;

		if(temp.first != temp.second)
			minHeap.push(temp);
	}
	
	while(minHeap.empty() == false)
	{
		temp = minHeap.top();
		minHeap.pop();
		
		for(int i = 0; i < n; i++)
		{
			if (rooms[i].second <= temp.first)
			{
				rooms[i] = temp;
				break;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (rooms[i] != nullPair)
			br++;
	}

	cout << br;
}

