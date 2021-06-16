// Koontrolnooo12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> sueverni;
	
    int n, m, k, xi,yi,wi,zi, t,l,q;
	cin >> n >> m;
	int graph[n][n];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = -1;
		}
	}
	
	for(int i=0; i<m; i++)
	{
		cin >> xi >> yi >> wi;
		graph[xi][yi] = wi;
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> zi;
		sueverni.insert(zi);
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (sueverni.find(graph[i][j]) != sueverni.end())
				graph[i][j] = -1;
		}
	}
	
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> l;
		vector<int> path(l,0);
		for(int j = 0; j < l; j++)
		{
			cin >> q;
			path[j] = q;
		}

		bool flag = true;

		for (unsigned i = 0; i < path.size() - 1; i++)
		{
			if (graph[path[i]][path[i + 1]] == -1)
			{
				flag = false;
				break;
			}
		}

		cout << flag;
		
	}
	
}
