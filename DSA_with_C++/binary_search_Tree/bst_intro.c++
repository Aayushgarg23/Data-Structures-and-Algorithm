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

void insertInBST(Node* &root, int data)
{
    if(root==NULL)
    {
        root = new Node(data);
    }
    else if(data >= root->val)
    {
        insertInBST(root->right,data);
    }
    else insertInBST(root->left,data);
}

void takeInput(Node* &root)
{
    cout << "Enter the data of node: "<<endl;
    int data;
    cin>>data;
    
    while(data!=-1)
    {
        insertInBST(root,data);
        cin>>data;
    }
}

bool Search(Node* root, int d)
{
    Node* temp = root;
    while(temp!=NULL){
    if(root->val==d)return true;
    else if(d < root->val) temp= root->right;
    else temp = root->left;
}
return false;
}
void levelOrderTraversal(Node* root)
{
    if(root==NULL)return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }

        else{
            cout << temp->val << " ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }

}

int main()
{
    Node* root =NULL;
    takeInput(root);
    levelOrderTraversal(root);
    if(Search(root,4)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}