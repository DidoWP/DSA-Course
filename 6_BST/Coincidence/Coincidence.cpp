// Coincidence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct BinaryTreeNode
{
	string val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode() : val(""), left(nullptr), right(nullptr) {}
	BinaryTreeNode(string val) : val(val), left(nullptr), right(nullptr) {}

	BinaryTreeNode* insert(BinaryTreeNode* root, string val)
	{
		if(!root)
		{
			return new BinaryTreeNode(val);
		}

		if (root->val == val)
			return root;
		
		if (val > root->val)
			root->right = insert(root->right, val);

		else if (val < root->val)
			root->left = insert(root->left, val);

		return root;
		
	}
	
	bool search(BinaryTreeNode* root, string val)
	{
		while (root != nullptr)
		{
			if (root->val == val)
				return true;
		
			if (root->val < val)
				root = root->right;

			else if (root->val > val)
				root = root->left;

		}
		return false;
	}
};

int main()
{

	int n, k;
	string input;
	vector<string> words;
	BinaryTreeNode* root = nullptr;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		root = root->insert(root, input);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> input;
		words.push_back(input);
	}
	
	for(int i = 0; i < k; i++)
	{
		if (root->search(root, words[i]))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}


