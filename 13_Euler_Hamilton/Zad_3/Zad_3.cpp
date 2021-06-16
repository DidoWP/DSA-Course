// Zad_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<int>> graph;

bool isGraphConnected(int n)
{
	unordered_set<int> edges;
	
	for (auto it : graph)
		if (!it.second.empty())
			edges.insert(it.second.begin(), it.second.end());

	if (edges.size() == n)
		return true;

	return false;
}

bool isEulerCycle()
{
	for (auto it : graph)
	{
		if (it.second.size() % 2 == 1)
			return false;
	}
	return true;
}

bool isEulerPath()
{
	int odd = 0;
	for (auto it : graph)
	{
		if (it.second.size() % 2 == 1)
			odd++;
	}
	
	return odd == 2;
}

int main()
{
    int q, n, m, a, b;
	
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int odd = 0;
		cin >> n >> m;
		
		for(int j = 0; j < m; j++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		if (isGraphConnected(n))
		{
			if (isEulerCycle())
				cout << "cycle";
			else if (isEulerPath())
				cout << "path";
			else
				cout << "none";
		}
		else cout << "none";

		graph.clear();
	}
	
}


////////////////////
