//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> starts;
	vector<pair<int, int>> ends;

	int tempInt, tempInt2;
	pair<int, int> tempPair;
	pair<int, int> tempPair2;

	for (int i = 0; i < n; i++)
	{
		cin >> tempInt;
		tempPair.first = tempInt;
		tempPair.second = i;
		starts.push_back(tempPair);

		cin >> tempInt2;
		tempPair2.first = tempInt2;
		tempPair2.second = i;
		ends.push_back(tempPair2);

	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	int counter = 0;

	for(int i=0; i<n; i++)
	{
		int currentID = starts[i].second;

		int endsSize = ends.size();

		for(int j=0; j<n; j++)
		{
			if(ends[j].second == currentID)
			{



				counter++;
				ends.erase(ends.begin() + j);
				starts.erase(starts.begin() + i);
				break;
			}
		}
	}
	cout << counter;

	return 0;
}

