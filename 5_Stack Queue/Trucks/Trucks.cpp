// Trucks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N, input;
    stack<int> trucks;
    bool flag = false;

    cin >> N;
    cin >> input;
    trucks.push(input);

    for (int i = 1; i < N; i++)
    {
        flag = false;
        cin >> input;

        while(trucks.top() > 0)
        {
            if (input < 0)
            {   
                if (input * -1 < trucks.top())
                {
                    flag = true;
                    break;
                } 
                else if (input * -1 == trucks.top())
                {
                    trucks.pop();
                    flag = true;
                    break;
                }
                else if (input * -1 > trucks.top())
                {
                    trucks.pop();
                } 
                if (trucks.empty()) break;
            }

            else break;
        }
        if (flag == false) trucks.push(input); 
    }

    if (trucks.empty())
    {
        cout << endl;
    }
    else
    {
        stack<int> result;

        while (!trucks.empty()) 
        {
            result.push (trucks.top());
            trucks.pop();
        }
        while (!result.empty())
        {
            cout << result.top() << " ";
            result.pop();
        }
    }
   
 
}
