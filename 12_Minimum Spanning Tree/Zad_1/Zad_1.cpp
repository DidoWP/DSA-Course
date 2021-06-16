// Zad_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> graph[], vector<bool>& used, int current)
{
	if(!used[current - 1])
	{
		used[current - 1] = true;
		for (int child : graph[current])
		{
			dfs(graph, used, child);
		}
	}
}

int main()
{
	
    int n, m;
	int roadFrom, to, counter = 0;
	cin >> n >> m;

	if(n == 1)
	{
		cout << 0;
		return 0;
	}
		
	
	vector<int> graph[1000001];
	vector<bool> visited(n,false);
	
	for(int i = 1; i <= m; i++)
	{
		cin >> roadFrom >> to;
		graph[roadFrom].push_back(to);
		graph[to].push_back(roadFrom);
		
		if (!visited[roadFrom - 1])
		{
			visited[roadFrom - 1] = true;
			counter++;
		}
		
		if (!visited[to - 1])
		{
			visited[to - 1] = true;
			counter++;
		}

		if(counter == n)
		{
			vector<bool> used(n, false);
			
			dfs(graph, used, 1);
			if (find(used.begin(), used.end(), false) == used.end())
			{
				cout << i;
				return 0;
			}
		}
	}

	cout << -1;
	

}
