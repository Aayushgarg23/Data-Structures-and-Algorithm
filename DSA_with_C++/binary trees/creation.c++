#include<iostream>
#include <queue>
#include<vector>
using namespace std;

class Node
{
    public:
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
    root = new Node(data);

    if(data==-1) return NULL;

    cout<<"Enter the node to insert in the left of: " << data << endl;
    root->left = buildTree(root->left);

    cout<<"Enter the node to insert in the right of: " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root)
{
    if(root==NULL) return NULL;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else
        {
            cout << temp->data <<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
    }
}   
}

void reverseLevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    vector<vector<int>> levels;  // store all levels

    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            currentLevel.push_back(temp->data);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        levels.push_back(currentLevel); // store this level
    }

    // Print levels in reverse order
    for (int i = levels.size() - 1; i >= 0; i--) {
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void inOrderTraversal(Node* root)
{
    
}
int main()
{
Node* root = NULL;
root=buildTree(root);
levelOrderTraversal(root);
}