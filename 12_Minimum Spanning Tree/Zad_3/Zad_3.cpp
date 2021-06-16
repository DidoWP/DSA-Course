// Zad_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


unordered_map<int, int> disjointSetMap;
unordered_map<int, int> rang;

int Find(int k)
{
	if (disjointSetMap[k] == k)
		return k;

	return Find(disjointSetMap[k]);
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);

	if(x == y)
		return;

	if (rang[x] < rang[y])
		disjointSetMap[x] = y;
	
	else if (rang[x] > rang[y])
		disjointSetMap[y] = x;

	else
	{
		disjointSetMap[x] = y;
		rang[y]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int n, m, from, to, q, input;
	cin >> n >> m;


	for(int i=0; i<n; i++)
	{
		disjointSetMap[i + 1] = i + 1;
		rang[i] = 0;
	}
	for(int i=0; i<m; i++)
	{	
		cin >> from >> to;
		Union(from, to);	
	}

	cin >> q;
	for(int i=0; i<q; i++)
	{
		cin >> input >> from >> to;

		if(input == 1)
		{
			if (Find(from) == Find(to))
				printf("%d", 1 );
			else printf("%d", 0 );
		}
		else
		{
			Union(from, to);
			//graph[from].push_back(to);
			//graph[to].push_back(from);
		}
	}
}