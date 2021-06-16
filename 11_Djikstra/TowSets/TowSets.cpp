// TowSets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100002];
int dist[100001];

void dijkstra(int v, int n)
{
	for (long long i = 0; i <= n; i++)
		dist[i] = INT32_MAX;

	dist[v] = 0;

	priority_queue<pair<int,int>> queue;
	queue.push({ v,0 });

	while (!queue.empty())
	{
		int currV = queue.top().first;
		int currPrice = queue.top().second;
		queue.pop();

		for (auto neighboor : adj[currV])
		{
			int w = neighboor.first;
			int p = neighboor.second;

			if (dist[w] == INT32_MAX)
			{
				dist[w] = currPrice + p;
				queue.push({ w,dist[w] });
			}
			else if (dist[w] > currPrice + p)
			{
				dist[w] = currPrice + p;
				queue.push({ w,dist[w] });
			}

		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;

	int price, x, y;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> price;

		adj[x].push_back({ y, price });
		adj[y].push_back({ x, price });
	}
	
	int k, q, Q, s, S[100000];
	
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> s;
		S[i] = s;
	}
	for (int i = 0; i < k; i++)
	{
		adj[n].push_back({ S[i],0 });
		adj[S[i]].push_back({ n,0 });
	}

	dijkstra(n, n);
	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		cin >> q;
		cout << dist[q] << endl;
	}

}
