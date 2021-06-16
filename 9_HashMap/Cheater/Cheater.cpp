// Cheater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int generateOptions(const int& boardSize, const int& shipsCount, const int& shipsWidth, const vector<int>& currentShots)
{
    int freeCells = 0, ships = 0;
    vector<int> board(boardSize, 0);

    for (unsigned i = 0; i < currentShots.size(); i++)
    {
        board[currentShots[i] - 1] = 1;
    }

    for (int i = 0; i < boardSize; i++)
    {
        if (board[i] == 0)
        {
            freeCells++;
            if (freeCells == shipsWidth)
            {
                ships++;
                freeCells = 0;
                i++;
            }
        }
        else
        {
            freeCells = 0;
        }

        if (ships == shipsCount)
            return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int boardSize, shipsCount, shipsWidth;
    int Q, shot;
    vector<int> allShots;
    vector<int> currentShots;

    cin >> boardSize >> shipsCount >> shipsWidth;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> shot;
        allShots.push_back(shot);
    }

    int maxShots = boardSize - shipsCount * shipsWidth;

    for (int i = 0; i < Q; i++)
    {
        if (i == maxShots)
        {
            cout << maxShots + 1;
            return 0;
        }
        currentShots.push_back(allShots[i]);

        if (generateOptions(boardSize, shipsCount, shipsWidth, currentShots) == 0)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
}

