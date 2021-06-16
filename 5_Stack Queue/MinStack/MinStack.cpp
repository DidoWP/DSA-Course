// MinStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


class Stack
{
private:
	int top;
	int currMin;
	int prevMin;
	int* arr;
	
public:
	Stack(int capacity);

	void push(int x);
	int peek();
	int min();
	void pop();
};


Stack::Stack(int capacity)
{
	arr = new int[capacity];
	top = -1;
	currMin = INT32_MAX;
	prevMin = INT32_MAX;
}

void Stack::push(int x)
{
	top++;
	arr[top] = x;
	if(currMin > x)
	{
		prevMin = currMin;
		currMin = x;
	}
}

int Stack::peek()
{
	return arr[top];
}

int Stack::min()
{
	return currMin;
}

void Stack::pop()
{
	if (currMin == arr[top])
		currMin = prevMin;
	
	top--;
}


int main()
{
    int N, numberInput;
	string input;

	cin >> N;

	Stack myStack(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> numberInput;
			myStack.push(numberInput);
		}
		else if (input == "pop")
		{
			myStack.pop();
		}
		else if (input == "min")
		{
			cout << myStack.min() << endl;
		}
		else if (input == "peek")
		{
			cout << myStack.peek() << endl;
		}
		else i--;
	}
}
