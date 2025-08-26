#include<iostream>
#include<stack>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void inorderTraversalRecursive(Node* root)
{
    if(root==NULL)return;

    inorderTraversalRecursive(root->left);
    cout<< root->data;
    inorderTraversalRecursive(root->right);
}

void inorderIterative(Node* root)
{
    Node* curr = root;
    stack<Node*>st;
    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout<< curr->data;
        curr= curr->right;
    }

}

void inorderMorris(Node* root)
{
    
}