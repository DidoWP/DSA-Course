// ShortestPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<long long, long long>> adj[100001];
long long dist[100001];
long long paths[100001];


void findShortestPath(long long v, long long n)
{
	for (long long i = 0; i <= n; i++)
		dist[i] = LLONG_MAX;
	
	dist[v] = 0;
	paths[v] = 1;
	
	
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> queue;
	queue.push({ 0,v });

	while (!queue.empty())
	{ 
		long long currV = queue.top().second;
		long long currPrice = queue.top().first;
		queue.pop();

		for(auto neighboor : adj[currV])
		{
			long long w = neighboor.second;
			long long p = neighboor.first;

			if(dist[w] == LLONG_MAX)
			{
				dist[w] = currPrice + p;
				queue.push({dist[w], w });
				paths[w] = paths[currV];
			}
			else if(dist[w] > currPrice + p)
			{
				dist[w] = currPrice + p;
				queue.push({dist[w], w });
				paths[w] = paths[currV];
			}
			
			else if(dist[w] == currPrice + p)
			{
				if(paths[w] + paths[currV] > 1000000007)
					paths[w] = paths[w] + paths[currV] - 1000000007;
				
				else
					paths[w] = paths[w] + paths[currV];
			}
		}
	}
}

int main()
{
    long long n, m;
	cin >> n >> m;

	long long price, x, y;

	for(long long i = 0; i < m; i++)
	{
		cin >> x >> y >> price;

		adj[x].push_back({price, y});
	}

	findShortestPath(1, n);

	if (dist[n] == LLONG_MAX)
		cout << -1 << " " << 0;
	else
		cout << dist[n] << " " << paths[n];
	
}

