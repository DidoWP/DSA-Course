// WalkingMedian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	double mod;
	cin >> n;
	vector<int> mylist;
	vector<int>::iterator it;

	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (i == 0) mylist.push_back(temp);
		else
		{
			bool flag = false;
			for(int j=0; j<i; j++)
			{
				it = mylist.begin() + j;
				if (temp < *it)
				{
					mylist.insert(it, temp);
					flag = true;
					break;
				}
			}
			if (flag == false) mylist.push_back(temp);
		}

		if (i == 0) {
			mod = temp; cout << mod << endl;
		}
		
		else if (i % 2 == 1)
		{
			mod = (mylist[i / 2] + mylist[i / 2 + 1]) / 2.0;
			cout << mod << endl;
		}
		else if (i % 2 == 0)
		{
			mod = mylist[i / 2];
			cout << mod << endl;
		}
	}
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
