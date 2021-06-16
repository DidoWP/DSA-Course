// IntervalMerger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void merge(vector< pair<int, char> >&, int l, int m, int r);
void mergeSort(vector< pair<int, char> >&, int l, int r);

int main()
{
	int n;
	cin >> n;
	vector< pair<int, char> > vect;
	
	for(int i=0; i<n*2; i++)
	{
		int temp;
		pair<int, char> tempPair;
		cin >> temp;
		
		tempPair.first = temp;
		if (i % 2 == 0) tempPair.second = 'B';
		else tempPair.second = 'E';

		vect.push_back(tempPair);
	}
	
	int vectSize = vect.size();

	mergeSort(vect, 0, vectSize - 1);

	int brBegins = 0, brEnds = 0;
	bool flag = false;
	
	for(int i=0; i<vectSize; i++)
	{
		if (vect[i].second == 'B') brBegins++;
		if (vect[i].second == 'E') brEnds++;

		for(int j=i+1; j<vectSize; j++)
		{
			if (vect[j].second == 'B') brBegins++;
			if (vect[j].second == 'E') brEnds++;

			if(vect[j].second == 'E' && brBegins == brEnds )
			{
				if (j == vectSize - 1)
				{
					cout << vect[i].first << " " << vect[j].first << endl;
					flag = true;
					break;
				}
				if(j < vectSize - 1 && vect[j].first != vect[j+1].first)
				{
					cout << vect[i].first << " " << vect[j].first << endl;
					i = j;
					break;
				}
			}		
		}
		if (flag == true) break;
	}
}

void merge(vector<pair<int,char>> &vectPair, int l, int m, int r)
{
	int n1 = m - l + 1; // Size of L vector
	int n2 = r - m;  // Size of R vector

	vector<pair<int,char>> L, R;

	for (int i = 0; i < n1; i++)
		L.push_back(vectPair[l + i]);
	
	for (int j = 0; j < n2; j++)
		R.push_back(vectPair[m + 1 + j]);
 
	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i].first <= R[j].first)
		{
			vectPair[k] = L[i];
			i++;
		}
		else
		{
			vectPair[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		vectPair[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vectPair[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<pair<int, char>> &vectPaid, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		mergeSort(vectPaid, l, m);
		mergeSort(vectPaid, m + 1, r);

		merge(vectPaid, l, m, r);
	}
}
