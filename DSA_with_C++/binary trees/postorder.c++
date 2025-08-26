#include<iostream>
#include<stack>
using namespace std;


class Node
{
    int data;
    Node* left ;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
}

void postorderRecursive(Node* root)
{
    if(root==NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout<< root->data;
    
}

void postorderIterative(Node* root)

{
    if(root==NULL)return;
    stack<Node*> st;
    while(!st.empty())
    {

    }
}