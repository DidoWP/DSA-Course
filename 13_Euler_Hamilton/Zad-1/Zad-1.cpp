

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<pair<int, char>>> mp;
pair<int, char> inputMatrix[26][26];

void dfs(vector<bool> visited, int current, int counter, int& pathCounter)
{
	if()
	if(visited[current] == false)
	{
		visited[current] = true;
		counter++;
		
		for(auto child : mp[current])
		{
			if (child.second != 'x')
				dfs(visited, child.first, counter, pathCounter);
		}
		
	}
	
}

int countPosiblePaths(int startPoint)
{
	vector<bool> visited(26*26, false);
	int trueCounter = 0, pathCounter = 0;
	
	dfs(visited, startPoint, trueCounter, pathCounter);

	return pathCounter;
}

int main()
{  
	int row, col, startPoint, intputCount = 0, x_counter = 0;
	char input;
    cin >> row >> col;

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> input;
			inputMatrix[i][j] = make_pair(intputCount, input);
			if (input == 'x')
				x_counter++;
			if (input == 's')
				startPoint = intputCount;
			intputCount++;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(i == row - 1 && j == col - 1){}
			
			else if(j == col - 1)
			{
				mp[inputMatrix[i][j].first].push_back({ inputMatrix[i + 1][j].first, inputMatrix[i + 1][j].second });
			}
			else if(i == row - 1)
			{
				mp[inputMatrix[i][j].first].push_back({ inputMatrix[i][j + 1].first, inputMatrix[i][j + 1].second });
			}
			else
			{
				mp[inputMatrix[i][j].first].push_back({ inputMatrix[i][j + 1].first, inputMatrix[i][j + 1].second });
				mp[inputMatrix[i][j].first].push_back({ inputMatrix[i + 1][j].first, inputMatrix[i + 1][j].second });
			}
		}
	}
	
	cout << countPosiblePaths(startPoint);
    
}