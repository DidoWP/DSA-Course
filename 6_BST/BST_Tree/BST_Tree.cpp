// BST_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    BinaryTreeNode* insert(BinaryTreeNode* root, int val);
    void DFS(BinaryTreeNode* root, vector<int>& vec);
    void BFS(BinaryTreeNode* root);
    BinaryTreeNode* deleteNode(BinaryTreeNode* root, int val);
	
};

void BinaryTreeNode::DFS(BinaryTreeNode* root, vector<int>& vec)
{
	if (root)
	{
		vec.push_back( root->val );
        DFS(root->left, vec);
        DFS(root->right, vec);
	}
}

void BinaryTreeNode::BFS(BinaryTreeNode* root)
{
    queue<BinaryTreeNode*> frontier;
    frontier.push(root);

    while (!frontier.empty())
    {
        BinaryTreeNode* currentNode = frontier.front();
        frontier.pop();
    	if(currentNode)
    	{
            frontier.push(currentNode->left);
    		cout << currentNode->val << " ";
            frontier.push(currentNode->right);
    	}
    }
}

BinaryTreeNode* BinaryTreeNode::deleteNode(BinaryTreeNode* root, int val)
{
	if(!root)
        return nullptr;

    if (val < root->val)
        root->left = deleteNode(root->left, val);

    else if (val > root->val)
        root->right = deleteNode(root->right, val);

    else
    {
        if (root->left == nullptr && root->right == nullptr)
            return nullptr;

        else if (root->left == nullptr)
            return root->right;

        else if (root->right == nullptr)
            return root->left;

        else
        {
            BinaryTreeNode* right_min = root->right;
            while (right_min->left)
            {
                right_min = right_min->left;
            }

            root->val = right_min->val;
            root->right = deleteNode(root->right, root->val);
        }
         
    }
    return root;
	
}

BinaryTreeNode* BinaryTreeNode::insert(BinaryTreeNode* root, int val)
{
	if(!root)
	{
        return new BinaryTreeNode(val);
	}

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


int main()
{
    int n, k, input;
    vector<int> result;

    cin >> n >> k;
    cin >> input;
    BinaryTreeNode* root = new BinaryTreeNode(input);

    for (int i = 1; i < n; i++)
    {
        cin >> input;
        root->insert(root, input);
    }

    root->DFS(root, result);
   
    int numToDel = result[n - k];
    for (auto v : result)
        cout << v << " ";
    cout << endl;
    cout << numToDel << endl << endl;
	
    result.clear();

    root->deleteNode(root, numToDel);

    root->BFS(root);

}

	


