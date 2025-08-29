/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

// for more understanding analyze the top view sol file first
// same complexities as top view

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  Code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>m;
        
        if(!root)return ans;
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            Node* head = temp.first;
            int level = temp.second;
            
            m[level] = head->data;
            
            if(head->left)q.push(make_pair(head->left,level+1));
            if(head->right)q.push(make_pair(head->right,level+1));
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};


/*  
----------------Using the DFS------------------
Time Complexity: O(N)
Each node is visited exactly once.
Work per node = constant O(1).

space: Recursive stack height = height of tree = O(H)  (stack + result)

Worst case (skewed tree) → O(N)
Best/Average case (balanced tree) → O(log N)
Answer vector (ans) = stores at most one element per level = O(H)

*/
 

class RightTraversal
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->right, ans, level+1);    
    solve(root->left, ans, level+1);
    
}
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};