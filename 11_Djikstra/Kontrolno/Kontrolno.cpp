// Kontrolno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[101];
vector<int> dist[101];
int visited[101];
int br;

void dijkstra(int v, int n, int range)
{
	br = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	queue.push({ 0,v });

	while (!queue.empty())
	{
		if(br == range)
			break;

		int currV = queue.top().second;
		int currPrice = queue.top().first;
		queue.pop();

		for (auto neighboor : adj[currV])
		{
			int w = neighboor.second;
			int p = neighboor.first;


			dist[w] = currPrice + p;
			
			queue.push({ dist[w], w });
			
		}
		br++;
	}
}


void printPossiblePaths(int u, int v, int k, int count, queue<int> queue) {
	//Add vertex u to queue;
	queue.push(u);
	//Mark u as visited;
	visited[u] = 1;

	for( auto w : adj[u])
	{
		if(visited[w.second] == 0)
		{
			if(count == k && before reaching 'v', ignore this vertex;

			if (count == k) {
				Print the path followed using the elements in the queue;
				Remove last element from the queue;
				return;
			}
			// Recur with the source as the new vertex and the updated queue
			printPossiblePaths(w, v, k, count, queue);
		}
	}
	Mark u as unvisited;
}

int main()
{
    int n, m;
	cin >> n >> m;
	
	int price, x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> price;

		adj[x].push_back({ price, y });
	}

	int range;
	cin >> range;

	for(int i = 1; i <= n; i++)
	{
		dijkstra(i,n,range);
	}
	

	
}

