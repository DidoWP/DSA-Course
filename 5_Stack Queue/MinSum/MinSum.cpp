// MinSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n,input,sum=0;
	int undoCounter = 0;
	cin >> n;
	stack<int> st;
	stack<int> q;
	
	for(int i=0; i<n; i++)
	{
		cin >> input;

		if(st.empty() && input < 0)
		{
			if(undoCounter > 0 && input == -2)
			{
				int temp = q.top();
				st.push(temp);
				q.pop();
				undoCounter--;
			}
		}
		
		else
		{
			if (input >= 0)
			{
				undoCounter = 0;
				while (!q.empty())
				{
					q.pop();
				}

				st.push(input);
			}
			else if (input == -1)
			{
				undoCounter++;
				q.push(st.top());
				st.pop();
			}
			else if (input == -2)
			{
				if (undoCounter > 0)
				{
					int temp = q.top();
					st.push(temp);
					q.pop();
					undoCounter--;
				}
			}
		}
	}

	while(!st.empty())
	{
		int temp = st.top();
		sum += temp;
		st.pop();
	}

	cout << sum;
}