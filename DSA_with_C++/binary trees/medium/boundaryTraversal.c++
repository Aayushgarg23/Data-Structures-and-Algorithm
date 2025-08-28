
/*
Time: O(N) Each node is visited at most once (in one of the three traversals)
Space: O(N) +  {Recursion stack = O(H) (height of tree) which will be takne by recursion}
*/


/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    void traversalLeft(Node* root, vector<int> &ans)
    {
          if(root==NULL || (root->left==NULL && root->right==NULL)) return;
          ans.push_back(root->data);
          if(root->left)traversalLeft(root->left,ans);
          else traversalLeft(root->right,ans);
    }
    void traversalRight(Node* root, vector<int> &ans)
    {
          if(root==NULL || (root->left==NULL && root->right==NULL)) return;
         
          if(root->right)traversalRight(root->right,ans);
          else traversalRight(root->left,ans);
          ans.push_back(root->data);
    }
    void traverseLeaf(Node* root, vector<int> &ans)
    {
        if(root==NULL)return;
        if(!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL)return ans;
        ans.push_back(root->data);
        // print left part
        traversalLeft(root->left,ans); // can't do right even if left absent bcz of cond. given
        
        traverseLeaf(root->left,ans); // for checking root's left side nodes
        traverseLeaf(root->right,ans); // for checking root's right side nodes
        
        traversalRight(root->right,ans); 
        return ans;
    }
};