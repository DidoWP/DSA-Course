// Exsames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second < b.second; 
    } 
};

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, br = 0;
	cin >> n;

	priority_queue<pi, vector<pi>, greater<pi>> students;
	priority_queue<pi, vector<pi>, myComp> queue;
	/*vector<pair<int, int>> rooms;

	pair<int, int> nullPair;
	nullPair.first = 0;
	nullPair.second = 0;

	for (int i = 0; i < n; i++)
	{
		rooms.push_back(nullPair);
	}*/

	pair<int, int> current;
	for (int i = 0; i < n; i++)
	{
		cin >> current.first;
		cin >> current.second;

		students.push(current);
	}

	pair<int, int> next;
	int firstTime = students.top().first;

	while (students.empty() == false)
	{
		current = students.top();
		students.pop();

		if(students.empty())
		{
			if (br + firstTime > current.first)
				br += (br + firstTime) - current.first;
			br += current.second;
			break;
		}
		next = students.top();

		queue.push(current);

		if (next.first <= br + firstTime)
		{
			queue.push(next);
			current = next;
		}
		else
		{
			while (queue.empty() == false)
			{
				pair<int, int> temp = queue.top();
				queue.pop();

				if (br + firstTime > temp.first)
					br += (br + firstTime) - temp.first;
				
				br +=  temp.second;

			}
		}
	}

	cout << br / n;
}
