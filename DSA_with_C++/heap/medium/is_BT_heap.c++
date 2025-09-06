#include<iostream>
#include<queue>
using namespace std;


// Structure of node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool isCBT(Node* root)
{
    if(root == NULL)
        return true;

    queue<Node*> q;
    q.push(root);
    bool flag = false; // flag to indicate whether we have seen a non-full node

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left)
        {
            if(flag) // if we have seen a non-full node before, then this node should not have any children
                return false;
            q.push(temp->left);
        }
        else
            flag = true; // we have seen a non-full node

        if(temp->right)
        {
            if(flag) // if we have seen a non-full node before, then this node should not have any children
                return false;
            q.push(temp->right);
        }
        else
            flag = true; // we have seen a non-full node
    }
    return true;

    // Time Complexity: O(n) where n is the number of nodes in the binary tree
    // Space Complexity: O(1)+O(n) {for the queue} = O(n) 
    // Auxiliary Space: O(h) where h is the height of the tree
}

// best method to find CBT is to do level order traversal and if we find a node which is not full then all the nodes after that should not have any children
// we have done that in the above function


bool isMaxOrder(Node* root)
{
    if(root == NULL)
        return true;

    if(root->left && root->data < root->left->data)
        return false;

    if(root->right && root->data < root->right->data)
        return false;

    return isMaxOrder(root->left) && isMaxOrder(root->right);

    // Time Complexity: O(n) where n is the number of nodes in the binary tree
    // Space Complexity: O(h) due to recursive stack space

    // Auxiliary Space: O(h) where h is the height of the tree
}
bool isBTHeap(Node* root)
{
    if(isCBT(root) && isMaxOrder(root))
        return true;
    return false;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    Node *heap = new Node(10);
    heap->left = new Node(9);
    heap->right = new Node(8);
    heap->left->left = new Node(7);
    heap->left->right = new Node(6);
    if(isBTHeap(root))
        cout<<"The given binary tree is a max-heap"<<endl;
    else
        cout<<"The given binary tree is not a max-heap"<<endl;

    if(isBTHeap(heap))
        cout<<"The given binary tree is a max-heap"<<endl;
    else
        cout<<"The given binary tree is not a max-heap"<<endl;

    return 0;
}