// DonerQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<char> queue;
	vector<int> distances;
	vector<int> distances2;
	int br = 0;
	int n; cin >> n;
	for(int i=0; i<n; i++)
	{
		char ch;
		cin >> ch;
		queue.push_back(ch);
	}
	
	for(int i=0; i<n; i++)
	{
		if(queue[i] == '-')
		{
			for(int j = i; j < n; j++)
			{
				if (queue[j] == '-') br++;
				else
				{
					distances.push_back(br);
					br = 0;
					break;
				}
			}
		}
		br = 0;
		
		if(queue[i] == '-' && i == 0)
		{
			for (int j = i; j < n; j++)
			{
				if (queue[j] == '-') br++;
				else
				{
					distances2.push_back(br);
					br = 0;
					break;
				}
			}
		}
	}

	if (queue[n - 1] == '-')
	{
		for(int i=n-1; i>=0; i--)
		{
			if (queue[i] == '-') br++;
			else
			{
				distances2.push_back(br);
				br = 0;
				break;
			}
		}
	}
	int max = 0, max2 = 0, result;
	if(distances.empty() && distances2.empty())
	{
		cout << -1;
		return 0;
	}
	for(int i=0; i<distances.size(); i++)
	{
		if(max < distances[i])
			max = distances[i];
	}
	for (int i=0; i<distances2.size(); i++)
	{
		if (max2 < distances2[i])
			max2 = distances2[i];
	}

	if (max % 2 == 0)  result = (max - 1) / 2; 
	else result = max / 2;
	if (result < max2 - 1) result = max2 - 1;

	cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
