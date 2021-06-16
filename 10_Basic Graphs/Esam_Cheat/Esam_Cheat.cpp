


#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int matrix[1001][1001];

int main()
{
	int m;
	cin >> m;
	int n, relation;

	for(int i = 0; i < m; i++)
	{
		cin >> n;
		for(int j = 0; j < n; j++)
		{
			cin >> relation;
			matrix[i][relation] = 1;
			matrix[relation][i] = 1;
		}
	}

	int Q, roadSize;
	cin >> Q;
	queue<int> road;
	
	for(int i =0; i< Q; i++)
	{
		cin >> roadSize;
		for(int j = 0; j < roadSize; j++)
		{
			cin >> relation;
			road.push(relation);
		}
		
		bool flag = true;
		while (road.empty() == false)
		{
			
			int front = road.front();
			road.pop();
			if (matrix[front][road.front()] != 1)
			{
				flag = false;
				break;
			}
			
		}
		if (flag == true)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	
	
}

