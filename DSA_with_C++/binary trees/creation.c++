#include<iostream>
#include <queue>
using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left =NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root)
{
    cout<< "Enter the node value";
    int data;
    cin>> data;
    Node* root = new node(data);

    if(data==-1) return;

    cout<<"Enter the node to insert in the left of: " << data << endl;
    root->left = buildTree(root->left);

    cout<<"Enter the node to insert in the right of: " << data << endl;
    root->left = buildTree(root->left);
    return root;
}

Node* levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    Node* temp = q.front();

    while(!q.empty())
    {
        if(temp==NULL){

        }
        else
        {
            cout << temp->data;
        }
    }
    
}

int main()
{

}