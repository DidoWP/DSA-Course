#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K, sum = 0, totalSum = 0, front;
	queue<int> myQueue;

	int minSize = INT32_MAX;
	
	cin >> N >> K;

	for(int i=0; i<N; i++)
	{
		int input;
		cin >> input;
		myQueue.push(input);
		sum += input;
		totalSum += input;
		
		while (sum >= K)
		{
			int size = myQueue.size();
			if (size < minSize) minSize = size;
				
			front = myQueue.front();
			sum -= front;
			myQueue.pop();
		}
	}
	if (totalSum < K) cout << -1;
	else
		cout << minSize;
}