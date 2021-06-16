
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[10001];

int dist[10001];
bool visited[10001];
int sorted[10001], used[10001], br;
int counter = 0;
int startt, endd;

//void topologSort(int v)
//{
//	used[v] = 1;
//	for(auto x : adj[v])
//	{
//		int w = x.first;
//		if (!used[w])
//			topologSort(w);
//	}
//
//	sorted[br--] = v;
//}

void dfs(int v, vector<pair<int,int>> adj[], int dist[], bool visited[])
{
	visited[v] = true;

	// Traverse for all its children 
	for (auto x : adj[v]) {

		
		// If not visited 
		if (!visited[x.first])
			dfs(x.first, adj, dist, visited);

		// Store the max of the paths
		dist[v] = max(dist[v], x.second + dist[x.first]);

		if (x.first == endd)
		{
			if (dist[v] == x.second + dist[x.first])
			{
				counter++;
			}
			else
			{
				counter = 0;
			}
		}
		
		
	}
}

//int fintLongestPath(int start, int end, int n)
//{
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i])
//			dfs(i, adj, dist, visited);
//	}
//
//	int ans = 0;
//
//	// Traverse and find the maximum of all dp[i] 
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, dist[i]);
//	}
//	return ans;
//}

int main()
{
	int n, m;
	cin >> n >> m;
	
	int time, x, y ;
	br = n - 1;
	
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> time;

		adj[x].push_back({ y, time });
	}

	cin >> startt >> endd;

	for (int i = 0; i < n; i++)
		dist[i] = INT32_MIN;
	dist[startt] = 0;
	
	dfs(startt, adj, dist, visited);
	cout << dist[endd] << " " << counter;
	
	/*topologSort(startt);

	for(int i = 0; i < n; i++)
	{
		cout << sorted[i];
	}*/

}







