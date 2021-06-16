// Zad_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n, x, y, max_deep = 0, min_index = INT32_MAX, result_index;


void dfs(vector<int> tree[], vector<bool>& vizited, int current, int index = 0)
{
	if(vizited[current] == false)
	{
		vizited[current] = true;
		for (int child : tree[current])
		{
			dfs(tree, vizited, child, index + 1);
			if (max_deep < index)
				max_deep = index;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	vector<int> tree[n];
	vector<int> result;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		vector<bool> vizited(n, false);
		
		dfs(tree, vizited, i);
		if(min_index == max_deep)
		{
			result.push_back(i);
		}
		if (min_index > max_deep)
		{
			result_index = result.size();
			result.push_back(i);
			min_index = max_deep;
		}
			
		max_deep = 0;
	}
	for (unsigned i = result_index; i < result.size(); i++)
	{
		cout << i << " ";
	} 
	
}

