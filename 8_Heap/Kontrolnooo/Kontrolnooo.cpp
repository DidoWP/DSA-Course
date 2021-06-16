
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int findCross(priority_queue<pair<int,int>> vec, int number, int q)
{
	int br = 0;
	bool flag = false;
	pair<int, int> current;

	for (int i = 0; i < q; i++)
	{
		current = vec.top();
		vec.pop();
		
		if (current.first <= number && number <= current.second)
		{
			br++;
			flag = true;
		}
		else if (number < current.first && flag == true)
		{
			break;
		}
			
	}

	return br;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, number;
	//bool flag = false;
	cin >> n >> q;

	pair<int, int> input;
	priority_queue<pair<int, int>> vec;
	
	
	for(int i=0; i<n; i++)
	{
		cin >> input.first >> input.second;
		vec.push(input);
	}

	for(int i=0; i<q; i++)
	{
		cin >> number;
		
		cout << findCross(vec, number, q) << " ";
	}
	
}