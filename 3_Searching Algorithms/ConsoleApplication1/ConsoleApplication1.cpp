
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>, int, int, int);
int binarySearchUpper(vector<int> vec, int left, int right, int x);

int main()
{
	int n, q;
	cin >> n >> q;

	vector<int> studentsPoints;
	vector<pair<int, int>> intervals;


	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		studentsPoints.push_back(temp);
	}

	for (int i = 0; i < q; i++)
	{
		pair<int, int> temp;
		cin >> temp.first;
		cin >> temp.second;
		intervals.push_back(temp);
	}

	sort(studentsPoints.begin(), studentsPoints.end());

	for(int i = 0; i < q; i++)
	{

		if(intervals[i].first > intervals[i].second)
		{
			cout << "0" << endl;
		}
		else
		{
			vector<int>::iterator begin;
			vector<int>::iterator end;

			begin = lower_bound(studentsPoints.begin(), studentsPoints.end(), intervals[i].first);
			end = upper_bound(studentsPoints.begin(), studentsPoints.end(), intervals[i].second);

			cout << (end - studentsPoints.begin()) - (begin - studentsPoints.begin()) + 1 << endl;
		}
	}
}
/*
int binarySearch(vector<int> vec, int left, int right, int x)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		if (vec[mid] >= x)
			return mid;

		if (vec[mid] > x)
			return binarySearch(vec, left, mid - 1, x);

		return binarySearch(vec, mid + 1, right, x);
	}
	if (left == right)
	{
		if (vec[left] >= x && left != 0) return left - 1;
		return left;
	}
	return -1;
}
int binarySearchUpper(vector<int> vec, int left, int right, int x)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		if (vec[mid] == x)
			return mid;

		if (vec[mid] > x)
			return binarySearch(vec, left, mid - 1, x);

		return binarySearch(vec, mid + 1, right, x);
	}
	if (left == right)
	{
		if (vec[left] >= x && left != 0) return left - 1;
		return left;
	}
	return -1;
}
*/
