
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;

struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};
int main()
{
    int n, input;
	cin >> n;

	unordered_map<pair<int,int>, int, hash_pair> matrix;
	unordered_set<pair<int, int>, hash_pair> burningTrees;
	
	priority_queue<int> result;

	int i_min = INT32_MAX, i_max = INT32_MIN, j_min = INT32_MAX, j_max = INT32_MIN;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			pair<int, int> temp(i, j);
			matrix[temp] = input;
			burningTrees.insert(temp);
		}
	}
	bool visited[4096][4096];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = { false };
	
	for(auto i = burningTrees.begin(); i != burningTrees.end(); ++i)
	{
		if (visited[i->first][i->second] == false)
		{
			pair<int, int> currentTree = make_pair(i->first, i->second);

			queue<pair<int, int>> que;
			que.push(currentTree);

			while (!que.empty())
			{
				currentTree = que.front();
				visited[currentTree.first][currentTree.second] = { true };
				
				que.pop();

				if (currentTree.first < i_min)
					i_min = currentTree.first;
				if (currentTree.first > i_max)
					i_max = currentTree.first;
				if (currentTree.second < j_min)
					j_min = currentTree.second;
				if (currentTree.second > j_max)
					j_max = currentTree.second;

				bool flag = false;
				if (currentTree.second + 1 < n && matrix[make_pair(currentTree.first, currentTree.second + 1)] == 1 && visited[currentTree.first][currentTree.second + 1] == false)
				{
					que.push(make_pair(currentTree.first, currentTree.second + 1));
					flag = true;
				}

				if (currentTree.first + 1 < n && matrix[make_pair(currentTree.first + 1, currentTree.second)] == 1 && visited[currentTree.first + 1][ currentTree.second] == false)
				{
					que.push(make_pair(currentTree.first + 1, currentTree.second));
					flag = true;
				}
				if (currentTree.second - 1 >= 0 && matrix[make_pair(currentTree.first, currentTree.second - 1)] == 1 && visited[currentTree.first][currentTree.second - 1] == false)
				{
					que.push(make_pair(currentTree.first, currentTree.second - 1));
					flag = true;
				}
				if (currentTree.first - 1 >= 0 && matrix[make_pair(currentTree.first - 1, currentTree.second)] == 1 && visited[currentTree.first - 1][ currentTree.second] == false)
				{
					que.push(make_pair(currentTree.first - 1, currentTree.second));
					flag = true;
				}

				//if (flag == false)
					//result.push(1);
			}

			result.push((i_max - i_min + 1) * (j_max - j_min + 1));
		}
		
	}

    while (result.empty() == false)
    {
		cout << result.top() << " ";
		result.pop();
    }
}


