// UniqueNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{						// задача от контролно е  по надолу в коментарите е истинската задача
	vector<int> vect1;
	vector<int> vect2;

	vector<int> resultVect;
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		vect1.push_back(temp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		vect2.push_back(temp);
	}
	
	int br = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vect1[i] == vect2[j]) 
			{
				if(br > 0)
				{
					flag = false;
					for(int k = 0; k < br; k++)
						if (vect1[i] == resultVect[k]) flag = true;
					
					if (flag == false)
					{
						resultVect.push_back(vect1[i]);
						br++;
					}
				}
				else
				{
					resultVect.push_back(vect1[i]);
					br++;
				}
				
			}
		}
	}
	int result = 0;
	for (int i = 0; i < br; i++)
	{
		result += resultVect[i];
	}
	
	cout << result;
    /*int  n, m, _n, _m;
	int brDigitsN = 0, brDigitsM = 0;
	
	cin >> n >> m;

	int digitsN[10];
	int digitsM[10];
	_n = n;
	_m = m;
	while(_n > 0)
	{
		_n /= 10;
		brDigitsN++;
	}
	while (_m > 0)
	{
		_m /= 10;
		brDigitsM++;
	}

	
	int firstDigitN = n % (brDigitsN * 10);
	int firstDigitM = n % (brDigitsM * 10);
	int uniqueNumb = 0;
	
	if(brDigitsN == brDigitsM)
	{
		if(firstDigitN == firstDigitM)
		{

			for(int i = n; i < (firstDigitN + 1) * brDigitsN; i++)
			{
				
			}
		}
	}*/
	
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
