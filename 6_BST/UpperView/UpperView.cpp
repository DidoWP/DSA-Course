// UpperView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

struct BSTNote
{
    int index;
    int x;
    int y;
    BSTNote* left;
    BSTNote* right;

    BSTNote() : index(0), x(0), y(0), left(nullptr), right(nullptr) {}
    BSTNote(int x, int y) : index(0), x(x), y(y), left(nullptr), right(nullptr) {}

    void insertLeft(BSTNote* root, int index)
    {
        root->left = new BSTNote(root->x - 1, root->y - 1);
        root->left->index = index;
    }

    void insertRight(BSTNote* root, int index)
    {
        root->right = new BSTNote(root->x + 1, root->y - 1);
        root->right->index = index;

    }
	
    void DFSPrint(BSTNote* root)
    {
        if (root)
        {
            DFSPrint(root->left);
            cout << root->index << "(" << root->x << root->y << ")  ";
            DFSPrint(root->right);
        }
    }

    int* BFSCrawling(BSTNote* root, int* result, int size)
    {
        queue<BSTNote*> frontier;
        frontier.push(root);

        result[size/2] = root->index;

        while (!frontier.empty())
        {
            BSTNote* current = frontier.front();
            frontier.pop();

            if (current)
            {
                if (result[size/2 + current->x] == -1)
                    result[size/2 + current->x] = current->index;

                frontier.push(current->left);
                frontier.push(current->right);
            }
        }
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, inputLeft, inputRight;
    BSTNote* root = new BSTNote();

    queue<BSTNote*> notes;
    notes.push(root);
	
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        BSTNote* current = notes.front();
        notes.pop();
        cin >> inputLeft;
        cin >> inputRight;
    	if(inputLeft != -1)
    	{
    		current->insertLeft(current, inputLeft);
            notes.push(current->left);
    	}
			
        if (inputRight != -1)
        {
            current->insertRight(current, inputRight);
            notes.push(current->right);
        }
    }

    //root->DFSPrint(root);
	
    int* result = new int[N];
    for (int i = 0; i < N; i++)
    {
        result[i] = -1;
    }

    root->BFSCrawling(root, result, N);

    for (int i = 0; i < N; i++)
    {
        if (result[i] != -1)
            cout << result[i] << " ";
    }

}

