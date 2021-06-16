
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
	
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB()
	{
        int br = 0;
        //queue<Node*> frontier;
    	deque<Node*> frontierD; 
        frontierD.push_back(root);
        
        while (!frontierD.empty())
        {
            br++;

            if(br % 2 == 1)
            {
                Node* currentNode = frontierD.front();
                frontierD.pop_front();
                if (currentNode->value)
                {
                    frontierD.push_front(currentNode->left);
                    cout << currentNode->value << " ";
                    frontierD.push_front(currentNode->right);
                }
            }
            else
            {
	            Node* currentNode = frontierD.front();
				frontierD.pop_front();
				if (currentNode->value)
				{
				    frontierD.push_back(currentNode->left);
					cout << currentNode->value << " ";
					frontierD.push_back(currentNode->right);
				}
            }
            
        }
    	
    }

private:
    //you can write helper functions if needed

	Node* root;

    Node* insert(Node* curNode, int value)
	{
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    tree.printSFB();
    return 0;
}