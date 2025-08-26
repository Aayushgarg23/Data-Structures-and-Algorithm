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
void preorderRecursive(Node* root)
{
    if(root==NULL)return;
    cout<< root->data;
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void preorderIterative(Node* root)
{
    if(root==NULL)return;
    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* curr = st.top();
        st.pop();

        cout<< curr->data;

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }

}