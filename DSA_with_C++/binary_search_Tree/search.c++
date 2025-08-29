#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//Here, h = height of the tree.
//If the tree is balanced, h = log n
//If the tree is skewed, h = n

// With the help of the recursion
// time: O(h)
// space: O(h)
bool SearchRecursive(Node* root, int d)
{
    if(root==NULL)return false;

    if(root->val==d) return true;
    else if(root->val < d)
    {
        return SearchRecursive(root->right,d);
    }
    else return SearchRecursive(root->left,d);

    return false;
}


//with the help of iteration
//Time Complexity: O(h)
//Space Complexity: O(1)
bool SearchIterative(Node* root, int d)
{
    Node* temp = root;
    while(!temp){
    if(root->val==d)return true;
    else if(d < root->val) temp= root->right;
    else temp = root->left;
}
return false;
}