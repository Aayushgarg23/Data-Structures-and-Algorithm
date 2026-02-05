#include <bits/stdc++.h>
using namespace std;

/*
Methods to compute height
A) Recursive DFS (bottom-up)
Idea: height(node) = 1 + max(height(left), height(right))
Time: O(N)
Space: O(H) recursion stack (H = tree height)
❌ Risk of deep recursion on skewed trees
*/
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int heightRecursive(Node* root)
{
    if(root==NULL)return -1;
    return(max(heightRecursive(root->left)+1,heightRecursive(root->right)+1));
}


/*
Iterative BFS (level order)
Idea: count levels using a queue; each level processed adds 1 to height/levels
Time: O(N)
Space: O(W) (W = max width of tree)
✅ No recursion; naturally gives #levels
❌ Needs a queue; still linear extra memory in worst width
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        queue<Node*> q;
        if(node==NULL) return -1;
        q.push(node);
        int height = -1;
        while(!q.empty())
        {
            height++;
            int level = int(q.size());
            for(int i=0;i<level;i++)
            {
                Node* front = q.front();
                q.pop();
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                
            }
        }
        return height;
        
    }
};

/*
C) Iterative DFS with explicit stack (track depth)
Idea: push (node, depth); track max depth seen
Time: O(N)
Space: O(H)
✅ No recursion; flexible
❌ Slightly more code than BFS
*/

