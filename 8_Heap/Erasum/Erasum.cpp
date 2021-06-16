// Erasum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(1);
	
	int n, input;

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater_equal<int>> minHeap;

	cin >> n;

	int lowerMax, upperMin;
	
	for(int i=0; i<n; i++)
	{
		cin >> input;
		if(i == 0)
		{
			maxHeap.push(input);
		}
		else if(maxHeap.size() > minHeap.size())
		{
			lowerMax = maxHeap.top();
			
			if(lowerMax > input)
			{
				maxHeap.pop();
				maxHeap.push(input);
				minHeap.push(lowerMax);
			}
			else if(lowerMax < input)
			{
				minHeap.push(input);
			}
		}
		else if(maxHeap.size() < minHeap.size())
		{
			upperMin = minHeap.top();

			if(upperMin < input)
			{
				minHeap.pop();
				minHeap.push(input);
				maxHeap.push(upperMin);
			}
			else if(upperMin > input)
			{
				maxHeap.push(input);
			}
		}
		else if(maxHeap.size() == minHeap.size())
		{
			lowerMax = maxHeap.top();
			if (input < lowerMax)
				maxHeap.push(input);
			else
				minHeap.push(input);
		}


		if(i % 2 == 0)
		{
			if (maxHeap.size() > minHeap.size())
				cout << (double)maxHeap.top() << '\n';
			else
				cout << (double)minHeap.top() << '\n';
		}
		else
		{
			double result;
			lowerMax = maxHeap.top();
			upperMin = minHeap.top();

			result = ((double)lowerMax + (double)upperMin) / 2.0;
			cout << result << '\n';
		}
		
	}
}