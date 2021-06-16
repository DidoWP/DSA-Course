// PerfectPrinter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& vec, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
    	
        if (vec[mid] == x)
            return mid;

        if (vec[mid] > x)
            return binarySearch(vec, l, mid - 1, x);

        return binarySearch(vec, mid + 1, r, x);
    }

    return -1;
}

int main()
{
    int N, Q;
	vector<int> vecN;
	vector<int> vecQ;

	cin >> N;
	for(int i=0; i<N; i++)
	{
		int temp;
		cin >> temp;
		vecN.push_back(temp);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int temp;
		cin >> temp;
		vecQ.push_back(temp);
	}

	int breakIndex = 0;
	for(int i=0; i<N; i++)
	{
		if(vecN[i] > vecN[i+1])
		{
			breakIndex = i;
			break;
		}
	}
	for(int i=0; i<Q; i++)
	{
		int result;
		result = binarySearch(vecN, 0, breakIndex, vecQ[i]);

		if (result == -1)
		{
			result = binarySearch(vecN, breakIndex + 1, N - 1, vecQ[i]);
			cout << result << endl;
		}
		else cout << result << endl;
	}
	
}