// MixedSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    int N, X, Y;
	cin >> N >> X >> Y;

	list<int> numbers;
	list<int> newList;
	
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	list<int>::iterator itBegin = numbers.begin();
	list<int>::iterator itEnd = numbers.begin();

	for(int i=0; i<X; i++)
	{
		if(itEnd == numbers.end())
		{
			numbers.reverse();
			for (auto v : numbers)
				std::cout << v << "\n";
			
			return 0;
		}
		advance(itEnd, 1);
	}
	

	bool flag = false;
	for(;;)
	{
		newList.splice(newList.begin(), numbers, itBegin, itEnd);
		newList.reverse();
		numbers.splice(itBegin, newList, newList.begin(), newList.end());
		
		if (flag == true) break;
		
		for(int i=0; i<X + Y; i++)
		{
			if( itEnd == numbers.end())
			{
				flag = true;
				break;
			}
			advance(itEnd, 1);
			advance(itBegin, 1);
		}
	}

	for (auto v : numbers)
		std::cout << v << "\n";
	
}

