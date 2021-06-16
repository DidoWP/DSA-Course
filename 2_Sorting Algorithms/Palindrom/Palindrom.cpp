// Palindrom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int const ASCII_CODES_SIZE = 123;

int main()
{
    int n;
	cin >> n;
	
	vector<string> words;

	for(int i=0; i<n; i++)
	{
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	for(int i=0; i<n; i++)
	{
		int* arr = new int[ASCII_CODES_SIZE]();
		
		int wordSize = words[i].size();
		for(int j=0; j < wordSize; j++)
		{
			arr[(int)words[i][j]]++;
		}

		int oddNumbers = 0;
		for (int k = 0; k < ASCII_CODES_SIZE; k++)
		{
			if (arr[k] % 2 == 1) oddNumbers++;
		}
		if (oddNumbers > 1) cout << "FALSE" << endl;
		else cout << "TRUE" << endl;
	}

}
